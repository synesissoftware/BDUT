# Contributing to BDUT <!-- omit in toc -->

Thank you for your interest in **BDUT**. This document covers how to report issues, propose changes, and validate them locally.


## Table of Contents <!-- omit in toc -->

- [Code of conduct](#code-of-conduct)
- [Reporting issues](#reporting-issues)
- [Pull requests](#pull-requests)
- [Development setup](#development-setup)
- [Coding standards](#coding-standards)
- [Documentation](#documentation)


## Code of conduct

Be respectful and constructive. Defect reports, feature requests, and pull requests are welcome on [GitHub](https://github.com/synesissoftware/BDUT).


## Reporting issues

Use [GitHub Issues](https://github.com/synesissoftware/BDUT/issues). Include:

- **BDUT** version (from `BDUT_VER_*` in **include/bdut/bdut.h** or the release tag)
- Operating system and architecture
- Compiler and version (e.g. Apple Clang 17, GCC 13, MSVC 2022)
- **CMake** version (if relevant)
- Minimal reproduction steps or a link to a branch

For build failures, attach the configure/build log. For assertion or output issues, show expected vs actual behaviour.


## Pull requests

1. Fork the repository and create a branch from **master** (or the current default branch).
2. Make focused changes; avoid unrelated formatting or drive-by edits.
3. Update **CHANGES.md** for user-visible changes.
4. Ensure the project builds and tests pass locally (see below).
5. Open a pull request with a clear description of the problem and solution.

Licensing: contributions are accepted under the same [3-clause BSD license](./LICENSE) as the project.


## Development setup

**BDUT** has no third-party dependencies. To build examples and tests:

```bash
./prepare_cmake.sh -m
./ctest_cmake.sh -M
```

Optional checks:

```bash
./run_all_scratch_tests.sh -M   # manual demos (some fail by design)
./run_all_examples.sh -M
```

To verify an installed package (after `cmake --install`), see the sample client under your local **scratch/BDUT** tree or follow [INSTALL.md](./INSTALL.md#consume-from-another-cmake-project).

Environment variables used by the Synesis CMake scripts:

| Variable | Purpose |
|----------|---------|
| `SIS_CMAKE_BUILD_DIR` | Override default `_build` output directory |
| `SIS_CMAKE_MAKE_COMMAND` | Override `make` / `mingw32-make.exe` |


## Coding standards

- **C** and **C++** sources in this repository are built with strict warnings as errors (`-Werror` / `/WX`) via **cmake/TargetMacros.cmake**.
- Match existing file layout and naming in **include/bdut/bdut.h** and surrounding Synesis boilerplate.
- Public API changes belong in **bdut.h** with Doxygen-style `/** @def ... */` comments for new macros.
- Version bumps: update `BDUT_VER_*` in **bdut.h** and align **test/unit/test.unit.version/entry.c**.


## Documentation

When adding or changing behaviour, update as appropriate:

- [README.md](./README.md) — overview, installation, API summary
- [INSTALL.md](./INSTALL.md) — build, install, consumer CMake
- [EXAMPLES.md](./EXAMPLES.md) — index of sample programs
- [vcpkg/README.md](./vcpkg/README.md) — overlay port install and maintainer notes
- [FAQ.md](./FAQ.md) — common questions
- [CHANGES.md](./CHANGES.md) — release notes


<!-- ########################### end of file ########################### -->
