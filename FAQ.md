# BDUT - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/BDUT/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [FAQs:](#faqs)
  - [Q1: "How do I build BDUT?"](#q1-how-do-i-build-bdut)
  - [Q2: "Does BDUT have its own unit-tests?"](#q2-does-bdut-have-its-own-unit-tests)
  - [Q3: "Why do some programs in the repository fail when I run them?"](#q3-why-do-some-programs-in-the-repository-fail-when-i-run-them)


# FAQs:


## Q1: "How do I build BDUT?"

**BDUT** is a single-file, header-only library, so you do **not** need to build anything to use it in your own project. Copy **include/bdut/bdut.h** into your tree (see [README.md](./README.md#manual-installation)) and `#include <bdut/bdut.h>`.

If you are working on **BDUT** itself, or want to run its examples and tests, use **CMake** via **prepare_cmake.sh** and **build_cmake.sh**. See [INSTALL.md](./INSTALL.md) for the full workflow. Installed headers and a `find_package(BDUT)` CMake package are also supported.


## Q2: "Does BDUT have its own unit-tests?"

Yes. Four unit-test programs under **test/unit/** are registered with **CTest** and run in CI:

* **test.unit.version** — version macros in **bdut.h**
* **test.unit.assert_true_false** — `BDUT_ASSERT_TRUE` / `BDUT_ASSERT_FALSE`
* **test.unit.compare** — equality and ordering comparison macros
* **test.unit.string_contains** — `BDUT_ASSERT_STRING_CONTAINS`

See [EXAMPLES.md](./EXAMPLES.md) for paths and macro coverage.

Additional programs under **test/scratch/** and **examples/** include intentional failures for documentation; **test.scratch.all_pass** is a manual combined passing demo.


## Q3: "Why do some programs in the repository fail when I run them?"

By design. **BDUT** is a unit-test *assertion* library, not a test runner with pass/fail reporting for multiple cases. The **examples/** tree and several **test/scratch/** programs contain failing assertions so you can see typical failure messages (file, line, function, and message text).

Programs intended to pass in CI are the **test.unit.*** programs under **test/unit/**. **test/scratch/test.scratch.all_pass** is an additional manual smoke test. See [README.md](./README.md#examples) for a minimal passing example and [EXAMPLES.md](./EXAMPLES.md) for a full program index.


<!-- ########################### end of file ########################### -->
