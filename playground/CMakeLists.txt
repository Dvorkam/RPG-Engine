include(CommonFcns)

set(LIB_NAME playground)
set(TESTS_EXEC ${LIB_NAME}_test)
set(TEST_FILES "foo.test.cpp")
set(MODULE_FILES "foo.ixx")
add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE FILE_SET CXX_MODULES FILES ${MODULE_FILES})

add_executable(${TESTS_EXEC} ${TEST_FILES})# ${TEST_FILES})
#target_sources(${TESTS_EXEC} PUBLIC FILE_SET CXX_MODULES FILES ${TEST_FILES})
target_link_libraries(${TESTS_EXEC} ${LIB_NAME} GTest::gtest GTest::gtest_main)
#target_link_libraries(${TESTS_EXEC} ${LIB_NAME})
gtest_discover_tests(${TESTS_EXEC})

install(TARGETS ${LIB_NAME} 
        EXPORT "${PROJECT_NAME}Targets"
        COMPONENT runtime
        COMPONENT dev
)
message(STATUS "INSTALLED: `${LIB_NAME}` library")

#MD_INSTALL()

#if(ALL_TEST_FILES)
#	list(APPEND ALL_TEST_FILES ${TEST_FILES})
#endif()
#set(PUBLIC_HEADER_LIST ${TEMPLATE_FILES})
#MD_ADD_AND_SETUP_LIB(STATIC)
#MD_ADD_AND_SETUP_GTESTS(${LIB_NAME})
