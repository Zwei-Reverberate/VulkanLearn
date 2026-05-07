#pragma once
#include <base/resource.h>

namespace rhi
{
    class SwapChain : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::SwapChain;
        }
        virtual uint32_t acquireNextImage(Semaphore* signalSemaphore) = 0;
        virtual void present(Semaphore* waitSemaphore) = 0;
        virtual Texture* getCurrentBackBuffer() = 0;
        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;
    };
}