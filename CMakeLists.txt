
cmake_minimum_required(VERSION 3.13)

project(prog CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE DEBUG)   ##or REALESE or WHATEVER IG...
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#(for stuff with connan)
include(${CMAKE_CURRENT_SOURCE_DIR}/conanFiles/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/conanFiles/bin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(prog 
   src/main.cpp
   src/hasher.cpp
   src/fileReader.cpp
   src/repo.cpp
   include/hasher.hpp
   include/fileReader.hpp
   include/repo.hpp
   )


target_link_libraries(prog ${CONAN_LIBS})

set_target_properties(prog PROPERTIES LINKER_LANGUAGE CXX)

