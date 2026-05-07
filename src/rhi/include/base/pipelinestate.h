#pragma once
#include <base/resource.h>

namespace rhi
{
    class PipelineState : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::PipelineState;
        }
    };
}