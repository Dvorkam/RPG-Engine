cmake_minimum_required(VERSION 3.26)
project("RPGEngine"
	VERSION 0.0.1
	DESCRIPTION "Project that aims to prepare tools for further project."
	LANGUAGES CXX
	)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

enable_testing()

find_package(doctest CONFIG REQUIRED)

include(${doctest_DIR}/doctest.cmake)
add_executable(MAIN_TEST "doctest.test.cpp")

doctest_discover_tests(MAIN_TEST)
target_link_libraries(MAIN_TEST PRIVATE doctest::doctest)

add_subdirectory("randEngine")
add_subdirectory("dicesLibrary")

#######################CONFIG GENERATION###########################
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)


install(
  EXPORT ${PROJECT_NAME}Targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${PROJECT_NAME}Targets.cmake
  )
export(
	EXPORT ${PROJECT_NAME}Targets
	FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
	NAMESPACE ${PROJECT_NAME}::
	)


configure_package_config_file( 
  "Config.cmake.in" 
  "${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  PATH_VARS
  CMAKE_INSTALL_LIBDIR
  )
message (${PROJECT_VERSION})
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${CMAKE_PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
  )

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )

  include(Packing)
