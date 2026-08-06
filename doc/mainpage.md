# BDUT {#mainpage}

**BDUT** (Brain-Dead Unit-Testing) is an extremely lightweight,
single-header unit-testing library for **C** and **C++**. It is intended to
be bundled into other projects where coupling to a more sophisticated
framework is undesirable.


## Quick start

```c
#include <bdut/bdut.h>

int main(int argc, char* argv[])
{
    BDUT_ASSERT_EQ(123, 123);
    BDUT_ASSERT_NE(123, 321);
    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");

    return BDUT_TESTS_PASSED(argc, argv);
}
```

Include `<bdut/bdut.h>`, write sequential assertions in `main()`, and return
\ref BDUT_TESTS_PASSED "BDUT_TESTS_PASSED(argc, argv)" when all have passed.
On failure, **BDUT** prints diagnostics to **stderr** and calls `exit(1)`.


## Assertion macros

| Macro | Summary |
| ----- | ------- |
| \ref BDUT_ASSERT_TRUE | Asserts that the expression is truey |
| \ref BDUT_ASSERT_FALSE | Asserts that the expression is falsey |
| \ref BDUT_ASSERT_EQ | Asserts `actual == expected` |
| \ref BDUT_ASSERT_NE | Asserts `actual != expected` |
| \ref BDUT_ASSERT_GE | Asserts `actual >= expected` |
| \ref BDUT_ASSERT_GT | Asserts `actual > expected` |
| \ref BDUT_ASSERT_LE | Asserts `actual <= expected` |
| \ref BDUT_ASSERT_LT | Asserts `actual < expected` |
| \ref BDUT_ASSERT_STRING_CONTAINS | Asserts `needle` is found in `haystack` |
| \ref BDUT_TESTS_PASSED | Reports success and returns `0` |

Version macros (\ref BDUT_VER_MAJOR, \ref BDUT_VER_MINOR,
\ref BDUT_VER_PATCH, \ref BDUT_VER, and related) are defined in
`<bdut/bdut.h>`.


## Installation

**BDUT** has no dependencies. Copy `include/bdut/bdut.h` into a consumer
project, or install via **CMake** and use `find_package(BDUT)` /
`BDUT::BDUT`. See
[INSTALL.md](https://github.com/synesissoftware/BDUT/blob/master/INSTALL.md)
for build, test, install, **FetchContent**, and **vcpkg** instructions.


## Related projects

Projects that use **BDUT** for testing include:

* [b64](https://github.com/synesissoftware/b64)
* [cstring](https://github.com/synesissoftware/cstring)
* [shwild](https://github.com/synesissoftware/shwild)

A fuller-featured related framework is
[xTests](https://github.com/synesissoftware/xTests).


<!-- ########################### end of file ########################### -->

