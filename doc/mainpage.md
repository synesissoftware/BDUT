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
    int object1 = 1;
    int object2 = 2;

    BDUT_ASSERT_EQ(123, 123);
    BDUT_ASSERT_NE(123, 321);
    BDUT_ASSERT_EQ_MSG(123, 123, "exact match");

    BDUT_ASSERT_PTR_EQ(&object1, &object1);
    BDUT_ASSERT_PTR_NE(&object1, &object2);

    BDUT_ASSERT_FP_EQ(0.3, 0.1 + 0.2);
    BDUT_ASSERT_FP_EQ_MARGIN(3.0, 3.0001, 0.0001);

    BDUT_ASSERT_STRING_CONTAINS("abc", "abcdef");
    BDUT_ASSERT_STRING_EQUAL("abc", "abc");
    BDUT_ASSERT_STRING_EQUAL_N("abc", "abd", 2);

    return BDUT_TESTS_PASSED(argc, argv);
}
```

Include `<bdut/bdut.h>`, write sequential assertions in `main()`, and return
\ref BDUT_TESTS_PASSED "BDUT_TESTS_PASSED(argc, argv)" when all have passed.
On failure, **BDUT** prints diagnostics to **stderr** and calls `exit(1)`.
Each `_MSG` form appends an optional `char const*` after the standard text.


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
| \ref BDUT_ASSERT_PTR_EQ | Asserts `actual` and `expected` are the same address |
| \ref BDUT_ASSERT_PTR_NE | Asserts `actual` and `expected` are different addresses |
| \ref BDUT_ASSERT_FP_EQ | Asserts approximate floating-point equality |
| \ref BDUT_ASSERT_FP_EQ_MARGIN | Asserts absolute-margin approximate equality |
| \ref BDUT_ASSERT_FP_EQ_MULTIPLIER | Asserts relative-multiplier approximate equality |
| \ref BDUT_ASSERT_FP_EQ_ZERO_MARGIN_OR_MULTIPLIER | Multiplier, or margin when either is zero |
| \ref BDUT_ASSERT_STRING_CONTAINS | Asserts `needle` is found in `haystack` |
| \ref BDUT_ASSERT_STRING_EQUAL | Asserts `actual` equals `expected` (`strcmp`) |
| \ref BDUT_ASSERT_STRING_EQUAL_N | Asserts the first `n` characters are equal (`strncmp`) |
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

