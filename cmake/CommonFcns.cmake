
#very simple marcro that assigns a non empty ARG value or a default value
#Required ARGS
#VAR is the variable value will be assigned to
#ARG is a an ARGN we want to check
#DEFAULT is the default value that will be used if arg is empty.

macro(MD_SET_VISIBILITY_VARIABLE VAR ARG DEFAULT)
message("ARG: ${ARG}")
    if (${ARG})
        set(${VAR} ${ARG})
        message("${VAR} set to ${ARG}")
    else()
        set(${VAR} ${DEFAULT})
        message("${VAR} set to DEFAULT")
    endif()
endmacro()

#function that adds library and sets up common target properties including build and install
#interfaces.
#Following variables need to be set in advance:
#
#set(LIB_NAME randomNumberEngine)
#set(HEADER_FILES "include/IGenerator.hpp" "include/GeneratorsPredefined.hpp")
#set(SOURCE_FILES "GeneratorsPredefined.cpp")
#set(TEST_FILES "GeneratorsPredefined.test.cpp")
#set(PUBLIC_HEADER_LIST ${HEADER_FILES})
#REQUIRED ARG
#ARG0 LIB_TYPE should be [STATIC|SHARED|INTERFACE] 
#OPTIONAL:
#ARG1 target_sources visibility (default PRIVATE)
#ARG2 target_include_directories visibility (default PUBLIC)
#ARG3 target_compile_features visibility (default PRIVATE)

function(MD_ADD_AND_SETUP_LIB LIB_TYPE)
    #message("ARG1: ${ARGV1}")
    #message("ARG2: ${ARGV2}")
    #message("ARG3: ${ARGV3}")
    MD_SET_VISIBILITY_VARIABLE(T_SRC_VIS "${ARGV1}" PRIVATE)
    MD_SET_VISIBILITY_VARIABLE(T_INC_DIR_VIS "${ARGV2}" PUBLIC)
    MD_SET_VISIBILITY_VARIABLE(T_COMP_F_VIS "${ARGV3}" PRIVATE)
    message("T_SRC_VIS: ${T_SRC_VIS}")
    message("T_INC_DIR_VIS: ${T_INC_DIR_VIS}")
    message("T_COMP_F_VIS: ${T_COMP_F_VIS}")

    add_library(${LIB_NAME} ${LIB_TYPE})
    target_sources(${LIB_NAME} ${T_SRC_VIS} ${SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})
    set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_LIST}")

    if (${LIB_TYPE} STREQUAL "INTERFACE")
        
        target_include_directories(${LIB_NAME} INTERFACE
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>  
            $<INSTALL_INTERFACE:include/${LIB_NAME}>  # <prefix>/include/mylib
            )
        target_compile_features(${LIB_NAME} INTERFACE cxx_std_20)
    else()
        target_include_directories(${LIB_NAME} ${T_INC_DIR_VIS}
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>  
            $<INSTALL_INTERFACE:include/${LIB_NAME}>  # <prefix>/include/mylib
            )
        target_compile_features(${LIB_NAME} ${T_COMP_F_VIS} cxx_std_20)
endif()
    
    
    
endfunction()

#function that adds discovers test in TEST_FILES and adds them to Testing using gtest
#Following variables need to be set in advance:
#set(LIB_NAME randomNumberEngine)
#set(TEST_FILES "GeneratorsPredefined.test.cpp")
#REQUIRED ARG
#ARG0 TEST_GROUP_NAME how the test in TES_FILES will be grouped 
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