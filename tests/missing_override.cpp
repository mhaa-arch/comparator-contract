#include <comparator/analog_comparator.hpp>

using namespace mhaa::comparator;

class Incomplete final : public AnalogComparator
{
public:
    void enable() override;
    void disable() override;
    bool output() const override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
