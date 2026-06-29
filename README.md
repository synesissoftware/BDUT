# BDUT <!-- omit in toc -->

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/BDUT.svg)](https://github.com/synesissoftware/BDUT/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/BDUT)](https://github.com/synesissoftware/BDUT/commits/master)
[![CMake on multiple platforms](https://github.com/synesissoftware/BDUT/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/synesissoftware/BDUT/actions/workflows/cmake-multi-platform.yml)

**B**rain-**D**ead **U**nit-**T**esting, extremely lightweight, single-header unit-testing for C and C++.


## Introduction

**B**rain-**D**ead **U**nit-**T**esting, is a very simple - simplistic, in fact - small, header-only, standalone library for C and C++. Its intent is to be bundled into other projects for which it is not desired to couple to a more sophisticated library.


## Table of Contents

- [Table of Contents](#table-of-contents)
- [Introduction](#introduction)
- [Installation](#installation)
  - [Manual installation](#manual-installation)
  - [CMake installation](#cmake-installation)
- [Examples](#examples)
  - [Passing example](#passing-example)
  - [Failure output examples](#failure-output-examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Installation

**BDUT** is a single-header library with **no dependencies**. You can use it by copying the header into your project, or by installing it via **CMake** and using `find_package()`. See [INSTALL.md](./INSTALL.md) for full build, test, and install instructions.


### Manual installation

Since **BDUT** is intended to be bundled into other open-source libraries, the simplest way to use it is to add a directory **bdut** under your project's **include** directory, into which you can then simply copy **bdut.h** from **include/bdut/bdut.h** in this distribution.

Your consumer code then uses:

```c
#include <bdut/bdut.h>
```


### CMake installation

**BDUT** provides CMake 3.20+ support: an `INTERFACE` library target, install rules, and an exported `BDUT-config.cmake` package so downstream projects can use `find_package(BDUT)`.

Quick start (from a clone of this repository):

```bash
./prepare_cmake.sh -m
sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
```

After installation, a CMake consumer can link against **BDUT** as follows:

```cmake
find_package(BDUT REQUIRED)

add_executable(my_tests main.c)
target_link_libraries(my_tests PRIVATE BDUT::BDUT)
```

Because **BDUT** is header-only, no library file is linked; the imported target supplies the include path. See [INSTALL.md](./INSTALL.md) for configure, build, test, and install options.


## Examples

**BDUT** is included into any C or C++ project by `#include`ing its header file and invoking assertion macros. Call `BDUT_TESTS_PASSED(argc, argv)` at the end of `main()` when all assertions have passed.


### Passing example

The following program (adapted from **test/scratch/test.scratch.all_pass**) exercises several macros and completes successfully:

```C
/* test/scratch/test.scratch.all_pass/main.c */

#include <bdut/bdut.h>

int main(int argc, char* argv[])
{
  BDUT_ASSERT_EQ(123, 123);
  BDUT_ASSERT_NE(123, 321);

  BDUT_ASSERT_LE(123, 123);
  BDUT_ASSERT_GE(123, 123);

  BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");

  return BDUT_TESTS_PASSED(argc, argv);
}
```

On success, output is along the lines of:

```bash
my_tests: ALL TESTS PASSED
```


### Failure output examples

The **examples/** programs under this repository are deliberately written to fail, in order to illustrate assertion output. For example:

```C
/* examples/c/example_1/main.c */

#include <bdut/bdut.h>

int main(int argc, char* argv[])
{
  BDUT_ASSERT_EQ(1, 2);

  return BDUT_TESTS_PASSED(argc, argv);
}
```

The output of this will be along the lines of:

```bash
~/open-source/BDUT/examples/c/example_1/main.c:7:main: assertion failed: actual value of `2` not equal-to expected value `1`
```

Similarly, the C++ example **examples/cpp/example_1** demonstrates string containment failure:

```C++
/* examples/cpp/example_1/main.cpp */

#include <bdut/bdut.h>

int main(int argc, char* argv[])
{
  BDUT_ASSERT_STRING_CONTAINS("", "abcdefghijklmnopqrstuvwxyz");
  BDUT_ASSERT_STRING_CONTAINS("abc", "abcdefghijklmnopqrstuvwxyz");

  /* this one will fail */
  BDUT_ASSERT_STRING_CONTAINS("abd", "abcdefghijklmnopqrstuvwxyz");

  return BDUT_TESTS_PASSED(argc, argv);
}
```

The output of this will be along the lines of:

```bash
~/open-source/BDUT/examples/cpp/example_1/main.cpp:15:main: assertion failed: actual string 'abcdefghijklmnopqrstuvwxyz' does not contain search string 'abd'
```


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/BDUT "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/BDUT.


### Dependencies

**BDUT** has no dependencies.


### Related projects

Projects in which **BDUT** is used for testing include:

* [**b64**](https://github.com/synesissoftware/b64)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**shwild**](https://github.com/synesissoftware/shwild)


### License

**BDUT** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
