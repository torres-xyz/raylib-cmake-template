# Using min version 3.26 for "copy_directory_if_different" command
cmake_minimum_required(VERSION 3.26)
project(raylib-template LANGUAGES CXX)

# Our Project
add_executable(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        COMPILE_WARNING_AS_ERROR ON) # Important! Treat warning as errors!
## From https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/
target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Weffc++
        -Wextra
        -Wconversion
        -Wsign-conversion)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
        constants.hpp)

## Adding the resources folder.
add_custom_target(copy_resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        ${CMAKE_CURRENT_LIST_DIR}/resources
        ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/resources
)
add_dependencies(${PROJECT_NAME} copy_resources)

# Dependencies
include(FetchContent)

## Fetch Raylib
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG ${RAYLIB_VERSION}
        SYSTEM # Makes it so that target_compile_options doesn't apply to this
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "") # We don't want to build raylib's (or any, since this is universal) examples
FetchContent_MakeAvailable(raylib)

## Fetch Raylib-CPP
set(RAYLIB_CPP_VERSION v5.5.0) # Keep this synced with ${RAYLIB_VERSION}
FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG ${RAYLIB_CPP_VERSION}
        SYSTEM # Makes it so that target_compile_options doesn't apply to this
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "") # We don't want to build raylib's (or any, since this is universal) examples
FetchContent_MakeAvailable(raylib_cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib raylib_cpp)
