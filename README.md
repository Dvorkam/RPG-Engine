# RPG-Engine

A collection of libraries to be pottentially used as a basis for further projects.

## Requirements
  1. vcpkg (for both)
    1. doctest  
  3. CMake 3.26 or newer (for both)
  4. Visual Studio 2022 17.4 (19.34) or newer (for windows)
  5. gcc 11 or newer (for linux)
  6. Ninja 1.11 or newer (for linux)

## Configure, build, test
Based on your platform use one of the presets
- cmake --preset={configurePresets}
  - vcpkgWin
  - vcpkgLinux
- cmake --build --preset={buildPresets}
  - debugWin / releaseWin
  - debugLinux / releaseLinux
- ctest --preset={testPresets}
  -testWin
  -testLinux
- cpack --preset={packagePresets}
  - TGZ
  - ZIP

## Requirements installation (for reference)

### vcpkg
#### Windows
  1. git clone https://github.com/Microsoft/vcpkg.git
  2. run .\vcpkg\bootstrap-vcpkg.bat
  3. (mandatory or you must change presets) add VCPKG_ROOT to enviromental variable with path leading to vcpkg
  4. (optional) add VCPKG_ROOT to PATH variable with path leading to vcpkg
  5. (optional) vcpkg integrate install
#### Linux
  1. git clone https://github.com/Microsoft/vcpkg.git
  2. .\vcpkg\bootstrap-vcpkg.sh
  3. (mandatory or you must change presets) add VCPKG_ROOT to enviromental variable with path leading to vcpkg
    1. nano ~/.bashrc 
    2.  add to the end of the file: export VCPKG_ROOT=[wherever it is]
  4. sudo ln -s [wherever it is]/vcpkg /usr/local/bin/vcpkg
  5. (optional) vcpkg integrate install

### CMake 3.26
#### Windows
  1. download https://cmake.org/download/ and install, adding it to path
 
#### Linux
  1. wget https://github.com/Kitware/CMake/releases/download/v3.26.0-rc6/cmake-3.26.0-rc6.tar.gz
  2. tar xzf cmake-3.26.0-rc6.tar.gz
  3. cd cmake-3.26.0-rc6
  4. ./configure
  5. gmake
  6. gmake install
### Ninja
1. sudo wget -qO /usr/local/bin/ninja.gz https://github.com/ninja-build/ninja/releases/latest/download/ninja-linux.zip
2. sudo gunzip /opt/ninja/ninja.gz
3. sudo chmod a+x /usr/local/bin/ninja

