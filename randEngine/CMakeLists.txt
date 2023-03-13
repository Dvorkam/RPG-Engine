include(CommonFcns)

set(LIB_NAME randomNumberEngine)
set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
set(SOURCE_FILES "GeneratorsPredefined.cpp")
set(TEST_FILES "GeneratorsPredefined.test.cpp")
set(PUBLIC_HEADER_LIST ${HEADER_FILES})

MD_ADD_AND_SETUP_LIB(STATIC)
MD_ADD_AND_SETUP_TESTS()
MD_INSTALL()
