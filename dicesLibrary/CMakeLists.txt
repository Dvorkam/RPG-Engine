include(CommonFcns)

set(LIB_NAME dicesLibrary)
set(TESTS_EXEC ${LIB_NAME}_test)
set(MODULE_FILES "Dice.ixx")
set(TEST_FILES "Dice.test.cpp")

add_library(${LIB_NAME})
target_sources(${LIB_NAME} PUBLIC FILE_SET CXX_MODULES FILES ${MODULE_FILES})
target_link_libraries(${LIB_NAME} randomNumberEngine)

add_executable(${TESTS_EXEC} ${TEST_FILES})
target_link_libraries(${TESTS_EXEC} ${LIB_NAME} GTest::gtest GTest::gtest_main)
gtest_discover_tests(${TESTS_EXEC})
MD_INSTALL()

#set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
#set(TEMPLATE_FILES "Dice.tpp")
#set(SOURCE_FILES "DiceSet.cpp")
# "DiceSet.test.cpp")
#set(PUBLIC_HEADER_LIST ${HEADER_FILES})
# Set the version of C++ for the project
# Create a library

#add_test(dicesLibrary Dice.test.cpp)



#MD_ADD_AND_SETUP_LIB(STATIC)
#MD_ADD_AND_SETUP_GTESTS(${LIB_NAME})
MD_INSTALL()