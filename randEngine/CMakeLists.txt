set(MODULE_NAME randomNumberEngine)

set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
set(SOURCE_FILES "GeneratorsPredefined.cpp")
set(TEST_FILES "GeneratorsPredefined.test.cpp")
if(ALL_TEST_FILES)
	list(APPEND ALL_TEST_FILES ${TEST_FILES})
endif()

add_library(${MODULE_NAME} ${SOURCE_FILES})
target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include>")


set(TEST GeneratorsPredefined_test)
add_executable(${TEST} "GeneratorsPredefined.test.cpp")
target_link_libraries(${TEST} ${MODULE_NAME} doctest::doctest)
doctest_discover_tests(${TEST})


EXPORT(
	TARGETS ${MODULE_NAME}
	FILE 	${MODULE_NAME}LibraryConfig.cmake
	)
