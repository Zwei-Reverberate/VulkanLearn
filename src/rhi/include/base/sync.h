#pragma once
#include <base/resource.h>

namespace rhi
{
    class Fence : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::Fence;
        }
        virtual bool isSignaled() = 0;
        virtual void wait() = 0;
        virtual void reset() = 0;
    };

    class Semaphore : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::Semaphore;
        }
    };

    class QueryHeap : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::QueryHeap;
        }
    };
}
