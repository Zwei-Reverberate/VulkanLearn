#pragma once
#include <span>
#include <base/resource.h>
#include <base/forward.h>
#include <base/structdefines.h>

namespace rhi
{
    class Device
    {
    public:
        virtual ~Device() = default;

        virtual Texture* createTexture(const TextureDesc&) = 0;
        virtual Buffer* createBuffer(const BufferDesc&) = 0;
        virtual Sampler* createSampler(const SamplerDesc&) = 0;
        virtual Shader* createShader(const ShaderDesc&) = 0;
        virtual PipelineState* createGraphicsPipeline(const GraphicsPipelineDesc&) = 0;
        virtual PipelineState* createComputePipeline(const ComputePipelineDesc&) = 0;

        virtual BindingLayout* createBindingLayout(const BindingLayoutDesc&) = 0;
        virtual BindingSet* createBindingSet(const BindingSetDesc&) = 0;

        virtual CommandList* createCommandList(QueueType type) = 0;
        virtual void executeCommandLists(QueueType type,
            std::span<CommandList*> commandLists,
            std::span<Semaphore*>   waitSemaphores,
            std::span<Semaphore*>   signalSemaphores,
            Fence* fence) = 0;

        virtual Fence* createFence() = 0;
        virtual Semaphore* createSemaphore() = 0;
        virtual QueryHeap* createQueryHeap() { return nullptr; }


        virtual SwapChain* createSwapChain(const SwapChainDesc& desc) = 0;

        virtual AccelerationStructure* createAccelerationStructure() { return nullptr; }

        virtual void advanceFrame() = 0;
        virtual void destroySoon(Resource* resource) = 0;

        virtual const DeviceCaps& getCaps() const = 0;
    };
}