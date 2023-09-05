#function that adds library and sets up common target properties something like this needs to be set in advance
#set(LIB_NAME randomNumberEngine)
#set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
#set(SOURCE_FILES "GeneratorsPredefined.cpp")
#set(TEST_FILES "GeneratorsPredefined.test.cpp")
#set(PUBLIC_HEADER_LIST ${HEADER_FILES})

function(MD_ADD_AND_SETUP_LIB LIB_TYPE)
    add_library(${LIB_NAME} ${LIB_TYPE})
    target_sources(${LIB_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})
    set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_LIST}")
    target_include_directories(${LIB_NAME} PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>  
        $<INSTALL_INTERFACE:include/${LIB_NAME}>  # <prefix>/include/mylib
    )
    target_compile_features(${LIB_NAME} PRIVATE cxx_std_20)
    
endfunction()

function(MD_ADD_AND_SETUP_TESTS)
    foreach(TEST IN LISTS TEST_FILES)
        add_executable(${TEST} ${TEST})
        target_link_libraries(${TEST} ${LIB_NAME} doctest::doctest)
        target_compile_features(${TEST} PRIVATE cxx_std_20)
        doctest_discover_tests(${TEST})
    endforeach()
endfunction()

function(MD_ADD_AND_SETUP_GTESTS TEST_GROUP_NAME)
    foreach(TEST IN LISTS TEST_FILES)
        add_executable(${TEST} ${TEST})
        target_link_libraries(${TEST} ${LIB_NAME} GTest::gtest_main)
        target_compile_features(${TEST} PRIVATE cxx_std_20)
        add_test(${TEST_GROUP_NAME} ${TEST})
        gtest_discover_tests(${TEST})
    endforeach()
endfunction()

function(MD_INSTALL)
    install(TARGETS ${LIB_NAME}
        EXPORT "${PROJECT_NAME}Targets"
        COMPONENT runtime
        PUBLIC_HEADER DESTINATION "include/${LIB_NAME}"
        COMPONENT dev
    )
endfunction()