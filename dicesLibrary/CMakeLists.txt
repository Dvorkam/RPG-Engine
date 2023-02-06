cmake_minimum_required(VERSION 3.21)
set(PROJECT_NAME dicesLibrary)
project(${PROJECT_NAME})

set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
set(SOURCE_FILES "Dice.cpp" "DiceSet.cpp")
set(TEST_FILES "Dice.test.cpp" "DiceSet.test.cpp")


add_library(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(PROJECT_IS_TOP_LEVEL)
	add_executable("${PROJECT_NAME}_TEST" ${HEADER_FILES} ${TEST_FILES})
	INSTALL(TARGETS "${PROJECT_NAME}_TEST")
else()
	target_sources(TEST_PROJECT PUBLIC ${HEADER_FILES} ${TEST_FILES})
endif()

INSTALL(TARGETS ${PROJECT_NAME})
EXPORT(
	TARGETS ${PROJECT_NAME}
	FILE 	${PROJECT_NAME}LibraryConfig.cmake
	)
