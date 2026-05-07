#pragma once
#include <cstdint>
#include <base/forward.h>

namespace rhi
{
    class Resource
    {
    public:
        virtual ~Resource() = default;
        virtual ResourceType getType() const = 0;
    };
}
