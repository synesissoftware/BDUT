# BDUT - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* \<none>


## Performance improvements

* \<none>


## Packaging improvements

* [x] ~~~**CMake** build, install, and package export (`bdut-config.cmake`)~~~ - ✅
* [x] ~~~**CTest** integration for unit tests~~~ - ✅
* [x] ~~~**GitHub Actions** multi-platform CI~~~ - ✅
* [x] ~~~Modular **ci.yml** / **ci-cell.yml** with install-smoke~~~ - ✅
* [x] ~~~**.sis/project_name.txt**~~~ - ✅
* [x] ~~~Merge **HISTORY.md** into **CHANGES.md**~~~ - ✅
* [x] ~~~README badges~~~ - ✅
* [x] ~~~Reconcile README, INSTALL, and FAQ with CMake/tests reality~~~ - ✅
* [x] ~~~**EXAMPLES.md** — index for **examples/** and **test/scratch/** (passing vs intentional failures)~~~ - ✅
* [x] ~~~**CONTRIBUTING.md** and GitHub issue/PR templates~~~ - ✅
* [x] ~~~Macro API reference table in README~~~ - ✅
* [x] ~~~Expand **CTest** coverage beyond **test.unit.version**~~~ - ✅
* [x] ~~~Remove stale **projects/core** references from example **CMakeLists.txt**; link examples/tests via **BDUT::BDUT**~~~ - ✅
* [x] ~~~Consumer **FetchContent** snippet in INSTALL~~~ - ✅
* [x] ~~~Optional **vcpkg** port~~~ - ✅ (overlay port in **vcpkg/ports/bdut/**)
* [ ] Move the allowed-to-fail lists (**.github/ci_examples_allowed_to_fail.txt**, **.github/ci_scratch_tests_allowed_to_fail.txt**) from **.github/** to **.sis/**, since they configure the helper scripts rather than GitHub; requires the gold **cmake-helpers** runners (**misc-dev-scripts**) to read them from the new location first;


<!-- ########################### end of file ########################### -->
