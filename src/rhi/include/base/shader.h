#pragma once
#include <resource.h>

namespace rhi
{
    class Shader : public Resource
    {
    public:
        ResourceType getType() const override
        {
            return ResourceType::Shader;
        }
    };
}