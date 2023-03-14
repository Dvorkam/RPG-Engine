find_path(doctest_INCLUDE_DIR "doctest.h"
                                HINTS 
                                "${CMAKE_SOURCE_PATH}../doctest/doctest"
                                "${doctest_DIR}/doctest"
                                )

if(doctest_INCLUDE_DIR-NOTFOUND)
message("Doctest library was not found")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(doctest DEFAULT_MSG
                                        doctest_INCLUDE_DIR
                                        )

mark_as_advanced(doctest_INCLUDE_DIR)