set(PROJECT_NAME randomNumberEngine)

set(HEADER_FILES "include/iRandomNumberGenerator.h" "include/randomNumberGenerator.tpp" "include/concurrentRandomNumberGenerator.tpp")
set(TEST_FILES "randomNumberGenerator.test.cpp" "concurrentRandomNumberGenerator.test.cpp")


add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

if(NOT TEST_PROJECT)
	add_executable("${PROJECT_NAME}_TEST" ${HEADER_FILES} ${TEST_FILES})
else()
	target_sources(TEST_PROJECT ${HEADER_FILES} ${TEST_FILES})
endif()
INSTALL(TARGETS ${PROJECT_NAME} "${PROJECT_NAME}_TEST")
EXPORT(
	TARGETS ${PROJECT_NAME}
	FILE 	${PROJECT_NAME}LibraryConfig.cmake
	)
