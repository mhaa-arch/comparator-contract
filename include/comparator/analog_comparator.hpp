#ifndef MHAA_COMPARATOR_ANALOG_COMPARATOR_HPP
#define MHAA_COMPARATOR_ANALOG_COMPARATOR_HPP

#include <comparator/types.hpp>

namespace mhaa
{
    namespace comparator
    {
        /** @brief Observes a comparison on one analog input pair. */
        class AnalogComparator
        {
        public:
            virtual ~AnalogComparator() = default;

            /** @brief Selects the positive and negative logical input routes. */
            virtual bool select_inputs(InputId positive, InputId negative) = 0;
            virtual void enable() = 0;
            virtual void disable() = 0;

            /** @brief Reports whether the enabled, settled comparator output is high. */
            virtual bool output() const = 0;
        };
    }
}

#endif
