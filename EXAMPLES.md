# BDUT - Examples <!-- omit in toc -->

This index lists the sample programs shipped with **BDUT**. See [README.md](./README.md#examples) for inline walkthroughs of a passing program and typical failure output.


## Table of Contents <!-- omit in toc -->

- [Overview](#overview)
- [Passing programs](#passing-programs)
- [Intentional failure demos](#intentional-failure-demos)
  - [examples/](#examples)
  - [test/scratch/](#testscratch)
- [Building and running](#building-and-running)


## Overview

**BDUT** is not a test runner: each program is a normal executable whose `main()` invokes assertion macros. Programs fall into two groups:

| Group | Purpose | Registered with CTest? |
|-------|---------|----------------------|
| **Passing** | Exercise macros that succeed; exit 0 after `BDUT_TESTS_PASSED()` | **test/unit/** (see below) |
| **Intentional failure** | Demonstrate assertion failure messages on stderr | No — run manually |

The **examples/** tree and most **test/scratch/** programs are in the second group by design.


## Passing programs

| Program | Source | Macros exercised |
|---------|--------|------------------|
| **test.unit.version** | [test/unit/test.unit.version/entry.c](./test/unit/test.unit.version/entry.c) | Version macros (`BDUT_VER_*`) |
| **test.unit.assert_true_false** | [test/unit/test.unit.assert_true_false/entry.c](./test/unit/test.unit.assert_true_false/entry.c) | `BDUT_ASSERT_TRUE`, `BDUT_ASSERT_FALSE`, and their `_MSG` forms |
| **test.unit.compare** | [test/unit/test.unit.compare/entry.c](./test/unit/test.unit.compare/entry.c) | `BDUT_ASSERT_EQ`, `BDUT_ASSERT_NE`, `BDUT_ASSERT_GE`, `BDUT_ASSERT_GT`, `BDUT_ASSERT_LE`, `BDUT_ASSERT_LT`, and their `_MSG` forms |
| **test.unit.pointer** | [test/unit/test.unit.pointer/entry.c](./test/unit/test.unit.pointer/entry.c) | `BDUT_ASSERT_PTR_EQ`, `BDUT_ASSERT_PTR_NE`, and their `_MSG` forms |
| **test.unit.string_contains** | [test/unit/test.unit.string_contains/entry.c](./test/unit/test.unit.string_contains/entry.c) | `BDUT_ASSERT_STRING_CONTAINS` and `BDUT_ASSERT_STRING_CONTAINS_MSG` |
| **test.unit.string_equal** | [test/unit/test.unit.string_equal/entry.c](./test/unit/test.unit.string_equal/entry.c) | `BDUT_ASSERT_STRING_EQUAL`, `BDUT_ASSERT_STRING_EQUAL_N`, and their `_MSG` forms |
| **test.scratch.all_pass** | [test/scratch/test.scratch.all_pass/main.c](./test/scratch/test.scratch.all_pass/main.c) | Combined macro smoke test (manual) |

All **test.unit.*** programs are registered with **CTest** and run in CI.

**test.scratch.all_pass** mirrors much of the unit coverage in one manual demo; the [README passing example](./README.md#passing-example) is adapted from it.


## Intentional failure demos

These programs contain at least one assertion that fails, to show file, line, function, and message output. Do not expect a zero exit code.

### examples/

Each public assertion has one C program and one C++ program. Each program shows a passing literal, a passing `actual` variable, a passing `_MSG` call, then one failing `_MSG` call on an `actual` variable.

| Program | Source | Demonstrates |
|---------|--------|--------------|
| **example.c.BDUT_ASSERT_EQ** | [examples/c/example.c.BDUT_ASSERT_EQ/main.c](./examples/c/example.c.BDUT_ASSERT_EQ/main.c) | `BDUT_ASSERT_EQ` / `BDUT_ASSERT_EQ_MSG` |
| **example.c.BDUT_ASSERT_FALSE** | [examples/c/example.c.BDUT_ASSERT_FALSE/main.c](./examples/c/example.c.BDUT_ASSERT_FALSE/main.c) | `BDUT_ASSERT_FALSE` / `BDUT_ASSERT_FALSE_MSG` |
| **example.c.BDUT_ASSERT_GE** | [examples/c/example.c.BDUT_ASSERT_GE/main.c](./examples/c/example.c.BDUT_ASSERT_GE/main.c) | `BDUT_ASSERT_GE` / `BDUT_ASSERT_GE_MSG` |
| **example.c.BDUT_ASSERT_GT** | [examples/c/example.c.BDUT_ASSERT_GT/main.c](./examples/c/example.c.BDUT_ASSERT_GT/main.c) | `BDUT_ASSERT_GT` / `BDUT_ASSERT_GT_MSG` |
| **example.c.BDUT_ASSERT_LE** | [examples/c/example.c.BDUT_ASSERT_LE/main.c](./examples/c/example.c.BDUT_ASSERT_LE/main.c) | `BDUT_ASSERT_LE` / `BDUT_ASSERT_LE_MSG` |
| **example.c.BDUT_ASSERT_LT** | [examples/c/example.c.BDUT_ASSERT_LT/main.c](./examples/c/example.c.BDUT_ASSERT_LT/main.c) | `BDUT_ASSERT_LT` / `BDUT_ASSERT_LT_MSG` |
| **example.c.BDUT_ASSERT_NE** | [examples/c/example.c.BDUT_ASSERT_NE/main.c](./examples/c/example.c.BDUT_ASSERT_NE/main.c) | `BDUT_ASSERT_NE` / `BDUT_ASSERT_NE_MSG` |
| **example.c.BDUT_ASSERT_PTR_EQ** | [examples/c/example.c.BDUT_ASSERT_PTR_EQ/main.c](./examples/c/example.c.BDUT_ASSERT_PTR_EQ/main.c) | `BDUT_ASSERT_PTR_EQ` / `BDUT_ASSERT_PTR_EQ_MSG` |
| **example.c.BDUT_ASSERT_PTR_NE** | [examples/c/example.c.BDUT_ASSERT_PTR_NE/main.c](./examples/c/example.c.BDUT_ASSERT_PTR_NE/main.c) | `BDUT_ASSERT_PTR_NE` / `BDUT_ASSERT_PTR_NE_MSG` |
| **example.c.BDUT_ASSERT_STRING_CONTAINS** | [examples/c/example.c.BDUT_ASSERT_STRING_CONTAINS/main.c](./examples/c/example.c.BDUT_ASSERT_STRING_CONTAINS/main.c) | `BDUT_ASSERT_STRING_CONTAINS` / `BDUT_ASSERT_STRING_CONTAINS_MSG` |
| **example.c.BDUT_ASSERT_STRING_EQUAL** | [examples/c/example.c.BDUT_ASSERT_STRING_EQUAL/main.c](./examples/c/example.c.BDUT_ASSERT_STRING_EQUAL/main.c) | `BDUT_ASSERT_STRING_EQUAL` / `BDUT_ASSERT_STRING_EQUAL_MSG` |
| **example.c.BDUT_ASSERT_STRING_EQUAL_N** | [examples/c/example.c.BDUT_ASSERT_STRING_EQUAL_N/main.c](./examples/c/example.c.BDUT_ASSERT_STRING_EQUAL_N/main.c) | `BDUT_ASSERT_STRING_EQUAL_N` / `BDUT_ASSERT_STRING_EQUAL_N_MSG` |
| **example.c.BDUT_ASSERT_TRUE** | [examples/c/example.c.BDUT_ASSERT_TRUE/main.c](./examples/c/example.c.BDUT_ASSERT_TRUE/main.c) | `BDUT_ASSERT_TRUE` / `BDUT_ASSERT_TRUE_MSG` |
| **example.cpp.BDUT_ASSERT_EQ** | [examples/cpp/example.cpp.BDUT_ASSERT_EQ/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_EQ/main.cpp) | `BDUT_ASSERT_EQ` / `BDUT_ASSERT_EQ_MSG` |
| **example.cpp.BDUT_ASSERT_FALSE** | [examples/cpp/example.cpp.BDUT_ASSERT_FALSE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_FALSE/main.cpp) | `BDUT_ASSERT_FALSE` / `BDUT_ASSERT_FALSE_MSG` |
| **example.cpp.BDUT_ASSERT_GE** | [examples/cpp/example.cpp.BDUT_ASSERT_GE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_GE/main.cpp) | `BDUT_ASSERT_GE` / `BDUT_ASSERT_GE_MSG` |
| **example.cpp.BDUT_ASSERT_GT** | [examples/cpp/example.cpp.BDUT_ASSERT_GT/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_GT/main.cpp) | `BDUT_ASSERT_GT` / `BDUT_ASSERT_GT_MSG` |
| **example.cpp.BDUT_ASSERT_LE** | [examples/cpp/example.cpp.BDUT_ASSERT_LE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_LE/main.cpp) | `BDUT_ASSERT_LE` / `BDUT_ASSERT_LE_MSG` |
| **example.cpp.BDUT_ASSERT_LT** | [examples/cpp/example.cpp.BDUT_ASSERT_LT/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_LT/main.cpp) | `BDUT_ASSERT_LT` / `BDUT_ASSERT_LT_MSG` |
| **example.cpp.BDUT_ASSERT_NE** | [examples/cpp/example.cpp.BDUT_ASSERT_NE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_NE/main.cpp) | `BDUT_ASSERT_NE` / `BDUT_ASSERT_NE_MSG` |
| **example.cpp.BDUT_ASSERT_PTR_EQ** | [examples/cpp/example.cpp.BDUT_ASSERT_PTR_EQ/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_PTR_EQ/main.cpp) | `BDUT_ASSERT_PTR_EQ` / `BDUT_ASSERT_PTR_EQ_MSG` |
| **example.cpp.BDUT_ASSERT_PTR_NE** | [examples/cpp/example.cpp.BDUT_ASSERT_PTR_NE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_PTR_NE/main.cpp) | `BDUT_ASSERT_PTR_NE` / `BDUT_ASSERT_PTR_NE_MSG` |
| **example.cpp.BDUT_ASSERT_STRING_CONTAINS** | [examples/cpp/example.cpp.BDUT_ASSERT_STRING_CONTAINS/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_STRING_CONTAINS/main.cpp) | `BDUT_ASSERT_STRING_CONTAINS` / `BDUT_ASSERT_STRING_CONTAINS_MSG` |
| **example.cpp.BDUT_ASSERT_STRING_EQUAL** | [examples/cpp/example.cpp.BDUT_ASSERT_STRING_EQUAL/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_STRING_EQUAL/main.cpp) | `BDUT_ASSERT_STRING_EQUAL` / `BDUT_ASSERT_STRING_EQUAL_MSG` |
| **example.cpp.BDUT_ASSERT_STRING_EQUAL_N** | [examples/cpp/example.cpp.BDUT_ASSERT_STRING_EQUAL_N/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_STRING_EQUAL_N/main.cpp) | `BDUT_ASSERT_STRING_EQUAL_N` / `BDUT_ASSERT_STRING_EQUAL_N_MSG` |
| **example.cpp.BDUT_ASSERT_TRUE** | [examples/cpp/example.cpp.BDUT_ASSERT_TRUE/main.cpp](./examples/cpp/example.cpp.BDUT_ASSERT_TRUE/main.cpp) | `BDUT_ASSERT_TRUE` / `BDUT_ASSERT_TRUE_MSG` |

### test/scratch/

| Program | Source | Demonstrates |
|---------|--------|--------------|
| **test.scratch.BDUT_ASSERT_TRUE** | [test/scratch/test.scratch.BDUT_ASSERT_TRUE/main.c](./test/scratch/test.scratch.BDUT_ASSERT_TRUE/main.c) | `BDUT_ASSERT_TRUE` / `BDUT_ASSERT_FALSE` and their `_MSG` forms (passing cases, then failing `BDUT_ASSERT_TRUE_MSG`) |
| **test.scratch.BDUT_ASSERT_LE** | [test/scratch/test.scratch.BDUT_ASSERT_LE/main.c](./test/scratch/test.scratch.BDUT_ASSERT_LE/main.c) | `BDUT_ASSERT_LE` / `BDUT_ASSERT_LE_MSG` failure |
| **test.scratch.BDUT_ASSERT_STRING_CONTAINS** | [test/scratch/test.scratch.BDUT_ASSERT_STRING_CONTAINS/main.c](./test/scratch/test.scratch.BDUT_ASSERT_STRING_CONTAINS/main.c) | `BDUT_ASSERT_STRING_CONTAINS` / `BDUT_ASSERT_STRING_CONTAINS_MSG` failure |


## Building and running

Configure and build with examples and tests enabled (default for **prepare_cmake.sh**):

```bash
./prepare_cmake.sh -m
```

Run automated tests:

```bash
./ctest_cmake.sh -M
```

Run helper scripts (build first if needed):

```bash
./run_all_unit_tests.sh -M      # CTest-backed unit test(s)
./run_all_scratch_tests.sh -M   # all scratch programs (includes failures)
./run_all_examples.sh -M        # examples/ failure demos
```

Run a single executable directly, e.g.:

```bash
./_build/test/scratch/test.scratch.all_pass/test.scratch.all_pass
./_build/examples/c/example.c.BDUT_ASSERT_EQ/example.c.BDUT_ASSERT_EQ    # exits non-zero
```


<!-- ########################### end of file ########################### -->
