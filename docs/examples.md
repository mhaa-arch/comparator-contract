# Analog Comparator Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The main conformance case selects a valid input pair, rejects an invalid pair, then enables the comparator. The separate `Events` fake overrides only the event capability. The program observes a pending rising-edge event and acknowledges it. The simulated flag is deliberately simple and does not simulate analog settling.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <comparator/analog_comparator.hpp>
#include <comparator/event_control.hpp>


using namespace mhaa::comparator;

class Events final : public EventControl
{
public:
    bool set_event(Event event) override { return event == Event::RisingEdge; }
    bool pending() const override { return flagged; }
    void clear_pending() override { flagged = false; }

    bool flagged = true;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
