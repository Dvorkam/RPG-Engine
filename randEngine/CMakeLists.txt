set(MODULE_NAME randomNumberEngine)

set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
set(SOURCE_FILES "GeneratorsPredefined.cpp")
set(TEST_FILES "GeneratorsPredefined.test.cpp")


add_library(${MODULE_NAME} ${SOURCE_FILES})
target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include>")

set(TEST GeneratorsPredefined_test)
add_executable(${TEST} "GeneratorsPredefined.test.cpp")
target_link_libraries(${TEST} ${MODULE_NAME})
add_test(${MODULE_NAME}_${TEST} ${TEST})


EXPORT(
	TARGETS ${MODULE_NAME}
	FILE 	${MODULE_NAME}LibraryConfig.cmake
	)
