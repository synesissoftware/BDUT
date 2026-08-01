# BDUT vcpkg overlay port

This directory contains an **overlay port** for [**vcpkg**](https://github.com/microsoft/vcpkg). It is intended for local testing and as a source for a future contribution to the main vcpkg registry.

## Install with overlay

From a clone of **BDUT** (this repository):

```bash
/path/to/vcpkg install bdut --overlay-ports=/path/to/BDUT/vcpkg/ports
```

To build the latest **master** instead of the pinned release in `vcpkg.json`:

```bash
/path/to/vcpkg install bdut --overlay-ports=/path/to/BDUT/vcpkg/ports --head
```

## Use from CMake

Pass the vcpkg toolchain file when configuring your project, then:

```cmake
find_package(BDUT CONFIG REQUIRED)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

See [INSTALL.md](../INSTALL.md#consume-via-vcpkg) for a full consumer example.

## Maintainers

When cutting a new **BDUT** release:

1. Update `version` in `ports/bdut/vcpkg.json`
2. Update `REF` / `${VERSION}` in `portfile.cmake` (via `vcpkg.json` version)
3. Refresh `SHA512` (set to `0`, run `vcpkg install`, copy the computed hash)

```bash
vcpkg install bdut --overlay-ports=./vcpkg/ports
```
