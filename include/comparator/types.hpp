#ifndef MHAA_COMPARATOR_TYPES_HPP
#define MHAA_COMPARATOR_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace comparator
    {
        enum class InputId : uint16_t
        {
        };

        enum class Event
        {
            Change,
            FallingEdge,
            RisingEdge
        };
    }
}

#endif
