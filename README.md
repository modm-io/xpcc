# XPCC for modm

Cross Platform Component Communication (XPCC) is the component-based
communication protocol of the [Roboterclub Aachen](https://www.roboterclub.rwth-aachen.de).
Components send actions, responses and events over a backend (usually CAN), and
an XML description of the components, actions and packets is translated into
C++ code.

XPCC was part of [modm](https://modm.io) until 2026 and now lives in this
lbuild repository. It is not developed further and only kept for existing
projects. New projects should use a modern CAN protocol like DroneCAN.


## Usage

Add this repository next to modm, for example as a git submodule, and add both
`repo.lb` files to your `project.xml`:

```xml
<library>
  <repositories>
    <repository><path>ext/modm/repo.lb</path></repository>
    <repository><path>ext/xpcc/repo.lb</path></repository>
  </repositories>
  <options>
    <option name="xpcc:generator:source">communication.xml</option>
    <option name="xpcc:generator:container">sender</option>
  </options>
  <modules>
    <module>xpcc:generator</module>
  </modules>
</library>
```

Modules:

- `xpcc:communication`: the C++ library, `#include <xpcc.hpp>`.
- `xpcc:generator`: generates the C++ code of the XML description during the
  build into `xpcc/generated` and compiles it into the xpcc library:
  `#include <identifier.hpp>`, `<packets.hpp>`, `<postman.hpp>`, ...
  Only the SCons build system (`modm:build:scons`) is supported, for which
  this repository generates its own `xpcc/SConscript`.
- `xpcc:menu`: `xpcc::CommunicatingView` for the `modm:ui:menu` module.


## Migrating from modm

modm 2026q4 deprecates its internal `modm:communication:xpcc` modules and
removes them in 2027q4. Both can be used side by side until then, but not in
the same project.

1. Add this repository to your project (see above).
2. Rename the modules and options:

   | modm (deprecated)                          | xpcc                        |
   |--------------------------------------------|-----------------------------|
   | `modm:communication:xpcc`                  | `xpcc:communication`        |
   | `modm:communication:xpcc:generator`        | `xpcc:generator`            |
   | `modm:ui:menu` (`CommunicatingView`)       | `xpcc:menu`                 |
   | `modm::xpcc:generator:source` etc.         | `xpcc:generator:source` etc.|
   | `modm::xpcc:generator:path`                | removed, always `xpcc/generated` |
   | `modm::xpcc:timeout.acknowledge` etc.      | `xpcc:communication:timeout.acknowledge` etc. |

3. Rename the includes:

   | modm (deprecated)                          | xpcc                        |
   |--------------------------------------------|-----------------------------|
   | `<modm/communication/xpcc.hpp>`            | `<xpcc.hpp>`                |
   | `<modm/communication/xpcc/...>`            | `<xpcc/...>`                |
   | `<modm/ui/menu/communicating_view.hpp>`    | `<xpcc/ui/communicating_view.hpp>` |

4. Rename `modm::CommunicatingView` and `modm::CommunicatingViewStack` to
   `xpcc::CommunicatingView` and `xpcc::CommunicatingViewStack`, and
   `modm::SmartPointer` to `xpcc::SmartPointer`.

Everything else in the `xpcc` namespace and the generated code stays the same.
If you set the generator path before, delete the old generated folder.


## Examples and tests

```sh
git submodule update --init
cd examples/sender && lbuild build && scons
cd test && make run-hosted-linux   # or run-hosted-darwin-arm64, compile-mega-2560-pro
```

The tests use modm's unit test runner and mocks from `ext/modm/test`.
