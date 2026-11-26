# Analog Comparator contract

## Input pair and level

[AnalogComparator](../include/comparator/analog_comparator.hpp) maps two `InputId` values to positive and negative routes on the same resource. Accept the wired pair on a fixed-input unit. If selection is rejected, keep the previous pair. The caller enables the comparator and allows the implementation's settling time before reading its output. A settled high output represents the positive input above the negative input, subject to accuracy and hysteresis.

## Event observation

[EventControl](../include/comparator/event_control.hpp) is optional. It selects a supported change or edge and exposes a pending flag and its acknowledgement. The condition can assert again after clearing. Define any relationship between that flag and interrupt routing in the target integration.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`comparator/types.hpp`](../include/comparator/types.hpp).
