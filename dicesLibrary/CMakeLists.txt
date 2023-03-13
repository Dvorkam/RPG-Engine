include(CommonFcns)

set(LIB_NAME dicesLibrary)
set(HEADER_FILES "include/Dice.hpp" "include/DiceSet.hpp")
set(SOURCE_FILES "Dice.cpp" "DiceSet.cpp")
set(TEST_FILES "Dice.test.cpp" "DiceSet.test.cpp")
set(PUBLIC_HEADER_LIST ${HEADER_FILES})

MD_ADD_AND_SETUP_LIB(STATIC)
MD_ADD_AND_SETUP_TESTS()
MD_INSTALL()