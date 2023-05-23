#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RPGEngine::randomNumberEngine" for configuration "Release"
set_property(TARGET RPGEngine::randomNumberEngine APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RPGEngine::randomNumberEngine PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/randomNumberEngine.lib"
  )

list(APPEND _cmake_import_check_targets RPGEngine::randomNumberEngine )
list(APPEND _cmake_import_check_files_for_RPGEngine::randomNumberEngine "${_IMPORT_PREFIX}/lib/randomNumberEngine.lib" )

# Import target "RPGEngine::dicesLibrary" for configuration "Release"
set_property(TARGET RPGEngine::dicesLibrary APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RPGEngine::dicesLibrary PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/dicesLibrary.lib"
  )

list(APPEND _cmake_import_check_targets RPGEngine::dicesLibrary )
list(APPEND _cmake_import_check_files_for_RPGEngine::dicesLibrary "${_IMPORT_PREFIX}/lib/dicesLibrary.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
