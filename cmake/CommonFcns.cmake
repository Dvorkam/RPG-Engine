#function that adds library and sets up common target properties something like this needs to be set in advance
#set(LIB_NAME randomNumberEngine)
#set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
#set(SOURCE_FILES "GeneratorsPredefined.cpp")
#set(TEST_FILES "GeneratorsPredefined.test.cpp")
#set(PUBLIC_HEADER_LIST ${HEADER_FILES})

function(MD_ADD_AND_SETUP_LIB LIB_TYPE)
    add_library(${LIB_NAME} ${LIB_TYPE} ${SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})
    target_include_directories(${LIB_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>  
    $<INSTALL_INTERFACE:include/${LIB_NAME}>  # <prefix>/include/mylib
    )
    set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_LIST}")
endfunction()

function(MD_ADD_AND_SETUP_TESTS)
    foreach(TEST IN LISTS TEST_FILES)
        add_executable(${TEST} ${TEST})
        target_link_libraries(${TEST} ${LIB_NAME} doctest::doctest)
        doctest_discover_tests(${TEST})
    endforeach()
endfunction()

function(MD_INSTALL)
    INSTALL(TARGETS ${LIB_NAME}
    EXPORT "${PROJECT_NAME}Targets" 
    PUBLIC_HEADER DESTINATION "include/${LIB_NAME}"
    )
endfunction()