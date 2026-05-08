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
        DepthStencilWrite, 
        DepthStencilRead,
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
