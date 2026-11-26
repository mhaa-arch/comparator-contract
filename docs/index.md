# Analog Comparator Contract guide

The instantaneous comparison and the pending event flag answer different questions. A pending event can survive a subsequent change in output. Read the settling and event rules before using the output or clearing a flag.

1. Start with [the contract](contract.md) for implementer obligations and capability boundaries.
2. Read [the conformance example](examples.md) for an implementation you can compile locally.
3. Consult [the portability notes](compatibility.md) before choosing a hardware mapping.