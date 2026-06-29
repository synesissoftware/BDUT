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


## Overview

**BDUT** is a single-header, header-only library. The public API is entirely in **include/bdut/bdut.h**. There is nothing to compile for normal use: you either copy that header into your project, or install it via CMake so that `find_package(BDUT)` provides the include path through an `INTERFACE` imported target.

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

The primary automated test is **test.unit.version**, which verifies version macros.

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

This installs **bdut.h** under **include/bdut/** and exports **BDUT-config.cmake** under **lib/cmake/BDUT/** (exact layout follows `GNUInstallDirs`).


### Consume from another CMake project

After installation (or when using **BDUT** as a subdirectory), link your test executable against the imported target:

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_project_tests C)

find_package(BDUT REQUIRED)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

No separate link library is required; **BDUT::BDUT** is an `INTERFACE` target that propagates the include directory.

Alternatively, add **BDUT** as a subdirectory without installing:

```cmake
add_subdirectory(path/to/BDUT)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```


<!-- ########################### end of file ########################### -->
