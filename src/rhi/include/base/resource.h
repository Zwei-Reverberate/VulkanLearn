#pragma once
#include <cstdint>

namespace rhi
{
    enum class RHIResourceType : uint32_t 
    {
        Unknown,
        Buffer,
        Texture,
        Sampler,
        Shader,
        PipelineState,
        BindingLayout,
        BindingSet,
        CommandList,
        Fence,
        Semaphore,
        SwapChain,
        QueryHeap,
        AccelerationStructure
    };

    class RHIResource 
    {
    public:
        virtual ~RHIResource() = default;
        virtual RHIResourceType getType() const = 0;
    };
}