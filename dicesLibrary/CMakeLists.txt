set(LIB_NAME dicesLibrary)

set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
set(SOURCE_FILES "Dice.cpp" "DiceSet.cpp")
set(TEST_FILES "Dice.test.cpp" "DiceSet.test.cpp")
set(PUBLIC_HEADER_LIST ${HEADER_FILES})

if(ALL_TEST_FILES)
	list(APPEND ALL_TEST_FILES ${TEST_FILES})
endif()


add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})


foreach(TEST IN LISTS TEST_FILES)
	add_executable(${TEST} ${TEST})
	target_link_libraries(${TEST} ${LIB_NAME} doctest::doctest)
	doctest_discover_tests(${TEST})
endforeach()

target_include_directories(${LIB_NAME} PUBLIC 
$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>  
$<INSTALL_INTERFACE:include/${LIB_NAME}>  # <prefix>/include/mylib
)
set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_LIST}")
INSTALL(TARGETS ${LIB_NAME}
		EXPORT "${PROJECT_NAME}Targets" 
		PUBLIC_HEADER DESTINATION "include/${LIB_NAME}"
		)
