#pragma once
#include <cstdint>

namespace rhi
{
    enum class ResourceType : uint32_t
    {
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
        QueryHeap,
        SwapChain,
        AccelerationStructure
    };

    enum class QueueType : uint8_t
    {
        Graphics = 0,
        Compute,
        Copy,
        Count
    };

    class Device;
    class Resource;
    class Texture;
    class Buffer;
    class Sampler;
    class Shader;
    class PipelineState;
    class BindingLayout;
    class BindingSet;
    class CommandList;
    class Fence;
    class Semaphore;
    class QueryHeap;
    class SwapChain;
    class AccelerationStructure;
}