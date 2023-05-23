include(CommonFcns)

set(LIB_NAME randomNumberEngine)
set(HEADER_FILES "")
set(TEMPLATE_FILES "IGenerator.tpp" "GeneratorsPredefined.tpp")
set(SOURCE_FILES "GeneratorsPredefined.cpp")
set(TEST_FILES "GeneratorsPredefined.test.cpp")
set(PUBLIC_HEADER_LIST ${TEMPLATE_FILES})

MD_ADD_AND_SETUP_LIB(STATIC)
MD_ADD_AND_SETUP_TESTS()
MD_INSTALL()
