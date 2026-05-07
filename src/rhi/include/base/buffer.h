#pragma once
#include <base/resource.h>

namespace rhi
{
    class Buffer : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::Buffer;
        }
        virtual uint64_t getSize() const = 0;
        virtual void* map() = 0;
        virtual void     unmap() = 0;
    };
}
