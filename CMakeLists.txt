cmake_minimum_required(VERSION 3.21)
project("theWorld"
	VERSION 0.0.1
	DESCRIPTION "Project that aims to simulate a world using population models."
	LANGUAGES CXX
	)
set (CMAKE_CXX_STANDARD 20)
#find_file(VCPKG_TOOLCHAIN_PATH "vcpkg.cmake"
#			HINTS "/opt/"
#			PATH_SUFFIXES "vcpkg/scripts/buildsystems/"
#			DOC "path to a vcpkg.cmake toolchain"
#			REQUIRED
#			)
#set(CMAKE_TOOLCHAIN_FILE ${VCPKG_TOOLCHAIN_PATH}
#    CACHE STRING "Vcpkg toolchain file")

enable_testing()
find_package(doctest CONFIG REQUIRED)

include(${doctest_DIR}/doctest.cmake)
add_executable(MAIN_TEST "doctest.test.cpp")

doctest_discover_tests(MAIN_TEST)
target_link_libraries(MAIN_TEST PRIVATE doctest::doctest)

add_subdirectory("randEngine")
add_subdirectory("dicesLibrary")




