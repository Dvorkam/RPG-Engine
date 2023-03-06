set(MODULE_NAME dicesLibrary)

set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
set(SOURCE_FILES "Dice.cpp" "DiceSet.cpp")
set(TEST_FILES "Dice.test.cpp" "DiceSet.test.cpp")
if(ALL_TEST_FILES)
	list(APPEND ALL_TEST_FILES ${TEST_FILES})
endif()


add_library(${MODULE_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


foreach(TEST IN LISTS TEST_FILES)
	add_executable(${TEST} ${TEST})
	target_link_libraries(${TEST} ${MODULE_NAME} doctest::doctest)
	doctest_discover_tests(${TEST})
endforeach()




INSTALL(TARGETS ${MODULE_NAME})
EXPORT(
	TARGETS ${MODULE_NAME}
	FILE 	${MODULE_NAME}LibraryConfig.cmake
	)
