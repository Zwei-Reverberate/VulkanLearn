#pragma once
#include <base/resource.h>
#include <base/enumdefines.h>

namespace rhi
{
    class Texture : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::Texture;
        }
        virtual uint32_t getWidth()  const = 0;
        virtual uint32_t getHeight() const = 0;
        virtual Format   getFormat() const = 0;
    };
}