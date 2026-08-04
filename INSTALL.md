# BDUT - Installation and Use <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Overview](#overview)
- [Manual use (no build required)](#manual-use-no-build-required)
- [Using CMake](#using-cmake)
  - [Obtain the latest distribution of **BDUT**](#obtain-the-latest-distribution-of-bdut)
  - [Prepare the CMake configuration](#prepare-the-cmake-configuration)
  - [Build](#build)
  - [Run tests](#run-tests)
  - [Install](#install)
  - [Consume from another CMake project](#consume-from-another-cmake-project)
    - [After install (`find_package`)](#after-install-find_package)
    - [Local subdirectory (`add_subdirectory`)](#local-subdirectory-add_subdirectory)
    - [Fetch at configure time (`FetchContent`)](#fetch-at-configure-time-fetchcontent)
    - [Via vcpkg](#via-vcpkg)


## Overview

**BDUT** is a single-header, header-only library. The public API is entirely in **include/bdut/bdut.h**. There is nothing to compile for normal use: you either copy that header into your project, or consume it from CMake via **`add_subdirectory`**, **`FetchContent`**, **`find_package(BDUT)`** after install, or **[vcpkg](#via-vcpkg)**.

The CMake machinery in this repository exists to build **examples** and **tests**, to run those tests via **CTest**, and to install headers and CMake package files for downstream consumers.


## Manual use (no build required)

1. Copy **include/bdut/bdut.h** into your project, e.g. as **include/bdut/bdut.h** relative to your source tree.
2. Add your **include** directory to the compiler's include path.
3. In your test source:

   ```c
   #include <bdut/bdut.h>
   ```

4. Use the assertion macros (e.g. `BDUT_ASSERT_EQ`, `BDUT_ASSERT_TRUE`) and return `BDUT_TESTS_PASSED(argc, argv)` from `main()` when all tests pass.


## Using CMake


### Obtain the latest distribution of **BDUT**

You can obtain a **.zip** or **.tar.gz** at the [Releases page](https://github.com/synesissoftware/BDUT/releases), e.g.:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ curl -L -O https://github.com/synesissoftware/BDUT/archive/refs/tags/0.4.0.tar.gz
$ tar xzf 0.4.0.tar.gz
$ cd BDUT-0.4.0
```

Or clone the repository:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone https://github.com/synesissoftware/BDUT.git
$ cd BDUT
```


### Prepare the CMake configuration

Prepare the CMake configuration via the **prepare_cmake.sh** script:

```bash
$ ./prepare_cmake.sh
```

By default this creates a **_build** directory under the project root. To use a different directory, set `SIS_CMAKE_BUILD_DIR`:

```bash
$ export SIS_CMAKE_BUILD_DIR=/tmp/BDUT
$ ./prepare_cmake.sh
```

Useful flags:

| Flag | Meaning |
|------|---------|
| `-m` / `--run-make` | Configure and build in one step |
| `-E` / `--disable-examples` | Do not build **examples/** |
| `-T` / `--disable-testing` | Do not build **test/** |
| `-d` / `--debug-configuration` | Use `Debug` instead of `Release` |
| `--mingw` | Use the MinGW Makefiles generator (Windows) |
| `--msvc-mt` | Use the static MSVC runtime (Windows) |

By default, **prepare_cmake.sh** enables both **BUILD_EXAMPLES** and **BUILD_TESTING**. To configure without building examples or tests:

```bash
$ ./prepare_cmake.sh -E -T
```


### Build

```bash
$ ./build_cmake.sh
```

> **NOTE**: If you passed `--run-make` (`-m`) to **prepare_cmake.sh**, this step can be skipped.


### Run tests

**BDUT** registers automated unit tests with **CTest**. After building with `BUILD_TESTING=ON`:

```bash
$ ./ctest_cmake.sh
```

Or, from the build directory:

```bash
$ ctest --test-dir ${SIS_CMAKE_BUILD_DIR:-./_build}
```

The primary automated tests are **test.unit.version**, **test.unit.assert_true_false**, **test.unit.compare**, and **test.unit.string_contains** under **test/unit/**.

Scratch programs under **test/scratch/** are built as examples (not registered with CTest) because several of them **fail deliberately** to demonstrate assertion output. Run them manually, e.g.:

```bash
$ ./_build/test/scratch/test.scratch.all_pass/test.scratch.all_pass
```

Or use the helper scripts:

```bash
$ ./run_all_unit_tests.sh -M    # unit tests only
$ ./run_all_scratch_tests.sh -M # scratch demos (includes intentional failures)
$ ./run_all_examples.sh -M      # README failure demos under examples/
```


### Install

Install headers and CMake package files on the host:

```bash
$ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
```

This installs **bdut.h** under **include/bdut/** and exports **bdut-config.cmake** under **lib/cmake/bdut/** (exact layout follows `GNUInstallDirs`).


### Consume from another CMake project

**BDUT** exposes an `INTERFACE` target **`BDUT::BDUT`** that propagates the include path. No separate link library is required.


#### After install (`find_package`)

After [installing](#install) **BDUT** on the host (or setting `CMAKE_PREFIX_PATH` to your install prefix):

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_project_tests C)

find_package(BDUT REQUIRED)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```


#### Local subdirectory (`add_subdirectory`)

If **BDUT** is already present in your tree (clone, submodule, or sibling directory):

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_project_tests C)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(path/to/BDUT)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

Disable **BDUT**'s own examples and tests so your project does not build them unnecessarily.


#### Fetch at configure time (`FetchContent`)

To download **BDUT** automatically at configure time (no system install and no submodule):

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_project_tests C)

include(FetchContent)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    BDUT
    GIT_REPOSITORY https://github.com/synesissoftware/BDUT.git
    GIT_TAG        0.4.0
)
FetchContent_MakeAvailable(BDUT)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

Pin **`GIT_TAG`** to a [release tag](https://github.com/synesissoftware/BDUT/releases) or a commit SHA for reproducible builds. **`GIT_SHALLOW TRUE`** is optional for faster clones.


#### Via vcpkg

An overlay port ships in **[vcpkg/ports/bdut](./vcpkg/ports/bdut/)** (see **[vcpkg/README.md](./vcpkg/README.md)**). Install into your vcpkg instance:

```bash
/path/to/vcpkg install bdut --overlay-ports=/path/to/BDUT/vcpkg/ports
```

For the latest **master** (instead of the pinned port version):

```bash
/path/to/vcpkg install bdut --overlay-ports=/path/to/BDUT/vcpkg/ports --head
```

Configure your project with the vcpkg toolchain file, then:

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_project_tests C)

find_package(BDUT CONFIG REQUIRED)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

Example:

```bash
cmake -B _build -S . -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build _build
```


<!-- ########################### end of file ########################### -->
