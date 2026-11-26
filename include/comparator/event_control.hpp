#ifndef MHAA_COMPARATOR_EVENT_CONTROL_HPP
#define MHAA_COMPARATOR_EVENT_CONTROL_HPP

#include <comparator/types.hpp>

namespace mhaa
{
    namespace comparator
    {
        /** @brief Configures and acknowledges comparator events on supporting targets. */
        class EventControl
        {
        public:
            virtual ~EventControl() = default;
            virtual bool set_event(Event event) = 0;
            virtual bool pending() const = 0;
            virtual void clear_pending() = 0;
        };
    }
}

#endif
