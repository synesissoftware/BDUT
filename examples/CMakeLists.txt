
if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()

	add_definitions(-DNOMINMAX)
endif(WIN32)

if((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	add_compile_options("/Zc:__cplusplus")
endif()


foreach(d c cpp)

	# The Linux TinyCC CI cell exercises the C examples only.
	if(("${d}" STREQUAL "cpp") AND (CMAKE_C_COMPILER_ID STREQUAL "TinyCC"))

		message(STATUS "skipping C++ examples: C compiler is TinyCC")

		continue()
	endif()

	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${d}")

		add_subdirectory(${d})
	endif()
endforeach()


# ############################## end of file ############################# #

