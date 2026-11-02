vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO synesissoftware/BDUT
    REF "${VERSION}"
    SHA512 0
    HEAD_REF master
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DBUILD_EXAMPLES=OFF
        -DBUILD_TESTING=OFF
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(
    PACKAGE_NAME BDUT
    CONFIG_PATH "lib/cmake/bdut"
)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(REMOVE_RECURSE
    "${CURRENT_PACKAGES_DIR}/debug/lib"
    "${CURRENT_PACKAGES_DIR}/lib"
)

file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage"
     DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
)

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
