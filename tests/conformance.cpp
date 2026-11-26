#include <comparator/analog_comparator.hpp>
#include <comparator/event_control.hpp>

#include <cassert>

using namespace mhaa::comparator;

class Fake final : public AnalogComparator
{
public:
    bool select_inputs(InputId positive, InputId negative) override
    {
        if (positive == negative)
        {
            return false;
        }
        selected = true;
        return true;
    }
    void enable() override { enabled = selected; }
    void disable() override { enabled = false; }
    bool output() const override { return enabled && positive_is_higher; }

    bool selected = false;
    bool enabled = false;
    bool positive_is_higher = true;
};

class Events final : public EventControl
{
public:
    bool set_event(Event event) override { return event == Event::RisingEdge; }
    bool pending() const override { return flagged; }
    void clear_pending() override { flagged = false; }

    bool flagged = true;
};

int main()
{
    Fake fake;
    AnalogComparator &comparator = fake;
    assert(comparator.select_inputs(InputId{}, static_cast<InputId>(1)));
    assert(!comparator.select_inputs(InputId{}, InputId{}));
    comparator.enable();
    assert(comparator.output());
    comparator.disable();
    Events fake_events;
    EventControl &events = fake_events;
    assert(!events.set_event(Event::FallingEdge));
    assert(events.set_event(Event::RisingEdge) && events.pending());
    events.clear_pending();
    assert(!events.pending());
}
