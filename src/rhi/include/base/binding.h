#pragma once
#include <base/resource.h>

namespace rhi
{
    class BindingLayout : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::BindingLayout;
        }
    };


    class BindingSet : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::BindingSet;
        }
    };
}