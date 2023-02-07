set(MODULE_NAME dicesLibrary)

set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
set(SOURCE_FILES "Dice.cpp" "DiceSet.cpp")
set(TEST_FILES "Dice.test.cpp" "DiceSet.test.cpp")
if(ALL_TEST_FILES)
	list(APPEND ALL_TEST_FILES ${TEST_FILES})
endif()


add_library(${MODULE_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(TEST Dice_test)
add_executable(${TEST} "Dice.test.cpp")
target_link_libraries(${TEST} ${MODULE_NAME})
add_test(${MODULE_NAME}_${TEST} ${TEST})

set(TEST DiceSet_test)
add_executable(${TEST} "DiceSet.test.cpp")
target_link_libraries(${TEST} ${MODULE_NAME})
add_test(${MODULE_NAME}_${TEST} ${TEST})



INSTALL(TARGETS ${MODULE_NAME})
EXPORT(
	TARGETS ${MODULE_NAME}
	FILE 	${MODULE_NAME}LibraryConfig.cmake
	)
