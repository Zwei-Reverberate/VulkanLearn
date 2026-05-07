#pragma once
#include <stdint.h>

namespace rhi
{
    enum class Format : uint32_t
    {
        Unknown,
        R8_UNORM,
        R8G8B8A8_UNORM,
        B8G8R8A8_UNORM,
        R32_FLOAT,
        R32G32B32A32_FLOAT,
        D32_FLOAT,
        D24_UNORM_S8_UINT,
        D32_FLOAT_S8_UINT,
        BC1_UNORM,
        BC3_UNORM,
        BC5_UNORM,
        BC7_UNORM
    };


    enum class TextureUsage : uint32_t
    {
        None = 0,
        RenderTarget = 1 << 0,
        DepthStencil = 1 << 1,
        ShaderResource = 1 << 2,
        UnorderedAccess = 1 << 3,
        CopySrc = 1 << 4,
        CopyDst = 1 << 5,
    };
    inline TextureUsage operator|(TextureUsage a, TextureUsage b)
    {
        return static_cast<TextureUsage>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
    }
    inline bool operator&(TextureUsage a, TextureUsage b)
    {
        return (static_cast<uint32_t>(a) & static_cast<uint32_t>(b)) != 0;
    }


    enum class BufferUsage : uint32_t
    {
        None = 0,
        Vertex = 1 << 0,
        Index = 1 << 1,
        Constant = 1 << 2,
        Storage = 1 << 3,
        Indirect = 1 << 4,
        CopySrc = 1 << 5,
        CopyDst = 1 << 6,
        AccelerationStructure = 1 << 7,
    };
    inline BufferUsage operator|(BufferUsage a, BufferUsage b)
    {
        return static_cast<BufferUsage>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
    }


    enum class ResourceState : uint32_t
    {
        Undefined,
        Common,
        RenderTarget,
        DepthStencilWrite, DepthStencilRead,
        ShaderResource,
        UnorderedAccess,
        CopySrc, CopyDst,
        Present,
        AccelerationStructureBuild,
        AccelerationStructureRead,
    };


    enum class PrimitiveTopology : uint8_t
    {
        PointList,
        LineList,
        TriangleList,
        TriangleStrip,
        PatchList
    };


    enum class CullMode : uint8_t
    {
        None,
        Front,
        Back
    };


    enum class FrontFace : uint8_t
    {
        CounterClockwise,
        Clockwise
    };


    enum class PolygonMode : uint8_t
    {
        Fill,
        Line
    };


    enum class BlendFactor : uint8_t
    {
        Zero,
        One,
        SrcColor,
        OneMinusSrcColor,
        SrcAlpha,
    };


    enum class BlendOp : uint8_t
    {
        Add,
        Subtract,
        ReverseSubtract,
        Min,
        Max
    };


    enum class LogicOp : uint8_t
    {
        Clear,
        Set,
        Copy
    };


    enum class CompareOp : uint8_t
    {
        Never,
        Less,
        Equal,
        LessEqual,
        Greater
    };


    enum class StencilOp : uint8_t
    {
        Keep,
        Zero,
        Replace,
        IncrementClamp
    };


    enum class Filter : uint8_t
    {
        Point,
        Linear,
        Anisotropic
    };


    enum class AddressMode : uint8_t
    {
        Wrap,
        Mirror,
        Clamp,
        Border
    };


    enum class BorderColor : uint8_t
    {
        FloatOpaqueBlack,
        FloatOpaqueWhite,
        IntOpaqueBlack,
        IntOpaqueWhite
    };


    enum class LoadOp : uint8_t
    {
        Load,
        Clear,
        DontCare
    };


    enum class StoreOp : uint8_t
    {
        Store,
        DontCare
    };


    enum class BindingType : uint8_t
    {
        UniformBuffer,
        StorageBuffer,
        Texture,
        Sampler,
        CombinedTextureSampler,
        AccelerationStructure
    };


    enum class ShaderVisibility : uint8_t
    {
        Vertex = 1 << 0,
        Pixel = 1 << 1,
        Compute = 1 << 2,
        AllGraphics = Vertex | Pixel,
        All = 0xFF
    };
    inline ShaderVisibility operator|(ShaderVisibility a, ShaderVisibility b)
    {
        return static_cast<ShaderVisibility>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
    }
}




#pragma once
#include <cstdint>
#include <span>
#include <string_view>
#include <base/enumdefines.h>
#include <base/forward.h>

namespace rhi
{
    struct TextureDesc
    {
        std::uint32_t width{ 1 };
        std::uint32_t height{ 1 };
        std::uint32_t depth{ 1 };
        std::uint32_t mips{ 1 };
        std::uint32_t arraySize{ 1 };
        std::uint32_t samples{ 1 };
        Format format{ Format::R8G8B8A8_UNORM };
        TextureUsage usage{ TextureUsage::ShaderResource };
        ResourceState initialState{ ResourceState::Undefined };
    };


    struct BufferDesc
    {
        std::uint64_t size{ 0 };
        BufferUsage usage{ BufferUsage::Vertex };
        bool hostVisible{ false };
    };


    struct SamplerDesc
    {
        Filter minFilter{ Filter::Linear };
        Filter magFilter{ Filter::Linear };
        Filter mipFilter{ Filter::Linear };
        AddressMode addressU{ AddressMode::Wrap };
        AddressMode addressV{ AddressMode::Wrap };
        AddressMode addressW{ AddressMode::Wrap };
        BorderColor border{ BorderColor::FloatOpaqueBlack };
        float maxAnisotropy{ 1.0f };
        CompareOp compareOp{ CompareOp::Never };
        float minLod{ 0.0f };
        float maxLod{ 1000.0f };
    };


    struct ShaderDesc
    {
        enum class Stage : std::uint8_t
        {
            Vertex,
            Pixel,
            Compute,
            Geometry,
            Mesh,
            Amplification,
            RayGen,
            Miss,
            ClosestHit,
            AnyHit,
            Intersection
        };

        Stage stage{ Stage::Vertex };
        std::span<const std::uint32_t> byteCode{};
        const char* entryPoint{ "main" };
    };


    struct VertexAttribute
    {
        std::uint32_t location{ 0 };
        std::uint32_t binding{ 0 };
        Format format{ Format::Unknown };
        std::uint32_t offset{ 0 };
    };


    struct VertexBinding
    {
        std::uint32_t binding{ 0 };
        std::uint32_t stride{ 0 };
        bool perInstance{ false };
    };


    struct GraphicsPipelineDesc
    {
        std::span<const ShaderDesc> shaders{};
        std::span<const VertexBinding> vertexBindings{};
        std::span<const VertexAttribute> vertexAttributes{};
        PrimitiveTopology topology{ PrimitiveTopology::TriangleList };
        bool primitiveRestart{ false };
        CullMode cullMode{ CullMode::Back };
        FrontFace frontFace{ FrontFace::CounterClockwise };
        PolygonMode polygonMode{ PolygonMode::Fill };
        bool depthClipEnable{ true };
        bool depthTestEnable{ true };
        bool depthWriteEnable{ true };
        CompareOp depthCompareOp{ CompareOp::Less };
        bool stencilEnable{ false };

        struct StencilState
        {
            StencilOp failOp{ StencilOp::Keep };
            StencilOp passOp{ StencilOp::Keep };
            StencilOp depthFailOp{ StencilOp::Keep };
            CompareOp compareOp{ CompareOp::Less };
            std::uint32_t compareMask{ 0xFF };
            std::uint32_t writeMask{ 0xFF };
        };

        StencilState frontStencil{};
        StencilState backStencil{};

        struct AttachmentBlend
        {
            bool blendEnable{ false };
            BlendFactor srcColor{ BlendFactor::One };
            BlendFactor dstColor{ BlendFactor::Zero };
            BlendFactor srcAlpha{ BlendFactor::One };
            BlendFactor dstAlpha{ BlendFactor::Zero };
            BlendOp colorOp{ BlendOp::Add };
            BlendOp alphaOp{ BlendOp::Add };
            LogicOp logicOp{ LogicOp::Copy };
            std::uint8_t writeMask{ 0xF };
        };

        std::span<const AttachmentBlend> attachments{};
        BindingLayout* bindingLayout{ nullptr };
        std::uint32_t colorAttachmentCount{ 0 };
        std::span<const Format> colorAttachmentFormats{};
        Format depthStencilFormat{ Format::Unknown };
        std::uint32_t subpassIndex{ 0 };
    };


    struct ComputePipelineDesc
    {
        ShaderDesc computeShader{};
        BindingLayout* bindingLayout{ nullptr };
    };


    struct BindingDesc
    {
        std::uint32_t slot{ 0 };
        BindingType type{ BindingType::UniformBuffer };
        ShaderVisibility visibility{ ShaderVisibility::All };
    };


    struct BindingSetLayoutDesc
    {
        std::uint32_t index{ 0 };
        std::span<const BindingDesc> bindings{};
    };


    struct BindingLayoutDesc
    {
        std::span<const BindingSetLayoutDesc> setLayouts{};
    };


    struct BindingResource
    {
        union
        {
            Buffer* buffer{ nullptr };
            Texture* texture;
            Sampler* sampler;
        };
        BindingType type{ BindingType::UniformBuffer };
    };


    struct BindingElement
    {
        std::uint32_t slot{ 0 };
        BindingResource resource{};
    };


    struct BindingSetDesc
    {
        BindingLayout* layout{ nullptr };
        std::uint32_t setIndex{ 0 };
        std::span<const BindingElement> bindings{};
    };


    struct RenderingAttachmentInfo
    {
        Texture* texture{ nullptr };
        LoadOp loadOp{ LoadOp::Clear };
        StoreOp storeOp{ StoreOp::Store };
    };


    struct RenderingInfo
    {
        std::span<const RenderingAttachmentInfo> colorAttachments{};
        const RenderingAttachmentInfo* depthAttachment{ nullptr };
        const RenderingAttachmentInfo* stencilAttachment{ nullptr };
        std::uint32_t width{ 0 };
        std::uint32_t height{ 0 };
    };


    struct TextureBarrier
    {
        Texture* texture{ nullptr };
        ResourceState srcState{ ResourceState::Undefined };
        ResourceState dstState{ ResourceState::Undefined };
        std::uint32_t mipLevel{ 0 };
        std::uint32_t mipCount{ 1 };
        std::uint32_t arraySlice{ 0 };
        std::uint32_t arraySize{ 1 };
    };


    struct BufferBarrier
    {
        Buffer* buffer{ nullptr };
        ResourceState srcState{ ResourceState::Undefined };
        ResourceState dstState{ ResourceState::Undefined };
    };


    struct Viewport
    {
        float x{ 0.0f };
        float y{ 0.0f };
        float width{ 0.0f };
        float height{ 0.0f };
        float minDepth{ 0.0f };
        float maxDepth{ 1.0f };
    };


    struct Rect
    {
        std::int32_t x{ 0 };
        std::int32_t y{ 0 };
        std::int32_t width{ 0 };
        std::int32_t height{ 0 };
    };


    struct SwapChainDesc
    {
        void* windowHandle{ nullptr };
        std::uint32_t width{ 0 };
        std::uint32_t height{ 0 };
        Format format{ Format::B8G8R8A8_UNORM };
        std::uint32_t bufferCount{ 3 };
        bool vSync{ true };
    };


    struct DeviceCaps
    {
        bool rayTracing{ false };
        bool meshShading{ false };
        bool bindlessTextures{ false };
        std::uint32_t maxAnisotropy{ 16 };
        std::uint32_t maxPushConstantsSize{ 128 };
    };
}