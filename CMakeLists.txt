# Using min version 3.26 for "copy_directory_if_different" command
cmake_minimum_required(VERSION 3.26)
project(raylib-template LANGUAGES C CXX)

set(CPP_VERSION cxx_std_23)
# From https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/
set(W_FLAGS -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion)

add_subdirectory(vendors)
add_subdirectory(src)

include(CTest)
add_subdirectory(tests)