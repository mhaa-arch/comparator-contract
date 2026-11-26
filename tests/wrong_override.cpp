#include <comparator/analog_comparator.hpp>

using namespace mhaa::comparator;

class WrongOverride final : public AnalogComparator
{
public:
    bool select_inputs(InputId positive, InputId negative) const override;
};
