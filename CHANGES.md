# BDUT Changes <!-- omit in toc -->


## 4th August 2026 - 0.4.1

* **CMakeLists.txt** — export package as lowercase **bdut-config.cmake** under **lib/cmake/bdut/** (fixes Linux `find_package(BDUT)` install-smoke; matches **Pantheios**/ **b64** convention);
* **ci.yml**, **INSTALL.md**, **README.md**, **vcpkg** — updated install-path / config-file references;


## 29th June 2026 - 0.4.1

* **README** — reconciled **Installation** (manual copy and CMake/`find_package(BDUT)`/`BDUT::BDUT`); added passing and failure **Examples** sections; fixed C example (`main.c`, `argc`/`argv`);
* **INSTALL.md** — replaced placeholder with full build, test, install, and consumer CMake guide;
* **FAQ.md** — updated Q1/Q2 for CMake and existing tests; added Q3 on intentional failure demos;
* **NEWS.md** — corrected **0.4.0** release tag link;
* **TODO.md** — replaced **xTests** boilerplate with **BDUT**-specific completed and pending OSS items;
* **CMakeLists.txt** — added **BDUT::BDUT** alias for in-tree builds;
* **examples/**, **test/** — link via **BDUT::BDUT** (removed stale **projects/core** references and directory-scope **include_directories**);
* **TargetMacros.cmake** — **define_automated_test_program** / **define_example_program** propagate the **BDUT** interface target;
* **run_all_unit_tests.sh**, **run_all_scratch_tests.sh** — removed **xTests** verbosity alias;
* **test.unit.version** — aligned version assertions with **0.4.1** (alpha 1) in **bdut.h**;
* **EXAMPLES.md** — index of passing and intentional-failure sample programs;
* **README** — macro API reference table; links to **EXAMPLES.md**;
* **CONTRIBUTING.md** — development setup, standards, and PR guidance;
* **.github/** — issue templates (bug, feature) and pull request template;
* **test/unit/** — added **test.unit.assert_true_false**, **test.unit.compare**, and **test.unit.string_contains** for **CTest**/CI;
* **INSTALL.md** — consumer **`FetchContent`** guide; split **`find_package`** / **`add_subdirectory`** / **`FetchContent`** sections;
* **CMakeLists.txt**, **cmake/BuildType.cmake** — use **`CMAKE_CURRENT_SOURCE_DIR`** so **BDUT** configures correctly as a subdirectory or **FetchContent** dependency;
* **vcpkg/** — overlay port (**vcpkg/ports/bdut/**) with **INSTALL.md** consumer instructions;
* **bdut.h** — mark assertion abort helpers **`BDUT_NORETURN_`**; rewrite **`BDUT_ASSERT_`** / **`BDUT_ASSERT_STRING_CONTAINS`** as **`do`/`while`** (fixes MSVC **C4702** with **/WX** on intentional-failure demos);
* **TargetMacros.cmake** — added **`define_failure_demo_program`** (**`/wd4702`**) for intentional-failure examples and scratch tests;


## 6th September 2025

* badges;
* added **run_all_unit_tests.cmd**;
* CMake helper scripts now define default make command as "mingw32-make.xe" if recognise MinGW;
* \*.sh : ~ moved info-lines into ./.sis/script_info_lines.txt;
* README;
* settings;
* .gitattributes;


## 30th August 2025 - 0.4.0 (alpha 3)

* GitHub Actions;


## 30th August 2025 - 0.4.0 (alpha 2)

* CTest compatibility;


## 30th August 2025 - 0.4.0 (alpha 1)

* added `BDUT_TESTS_PASSED()`;


## 30th August 2025 - 0.3.3

* Fixed `BDUT_ASSERT_GE()`, `BDUT_ASSERT_GT()`, `BDUT_ASSERT_LE()`, `BDUT_ASSERT_LT()`;
* Added **test.unit.version**;


## 15th May 2025 - 0.3.2

* Minor warnings (observed with Visual C++);


## 6th May 2025 - 0.3.2 (release candidate 1)

Summary:
--------

* Multiple CMake-related improvements;

Changes:
--------

Multiple CMake-related improvements:
 * added and applied target macros;
 * added '--mingw' flag to **prepare_cmake.sh**;
 * added '--list-only' flag to **run_all_unit_tests.sh**;
 * added **run_all_scratch_tests.sh**;
 * ARM64 support;


## 0.2.0 (alpha5) - 7th March 2024

* added **CMake** support and boilerplate files;
* added `BDUT_ASSERT_EQ()`, `BDUT_ASSERT_NE()` macros;
* added `BDUT_ASSERT_GE()`, `BDUT_ASSERT_GT()`, `BDUT_ASSERT_LE()` macros;
* `BDUT_report_string_contains_failure_and_abort_()` now implemented in terms of `std::snprintf()` rather than `std::sprintf()`;


## 0.2.0 (alpha2) - 11th January 2024

Minor mod


## 0.2.0 (alpha1) - 11th January 2024

First port out of [**shwild**](https:github.com/synesissoftware/shwild) (as of version 0.11.5)


All history before this day is moot!


<!-- ########################### end of file ########################### -->

