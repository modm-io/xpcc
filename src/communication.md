# Cross Platform Component Communication (XPCC)

XPCC is the component-based communication protocol of the Roboterclub Aachen.
Components send actions, responses and events over a backend (usually CAN) and
an XML description of the components, actions and packets is translated into
C++ code by the `xpcc:generator` module.

Include everything with `#include <xpcc.hpp>`.

XPCC is not developed further and is only kept for existing projects.
New projects should use a modern CAN protocol like DroneCAN.
