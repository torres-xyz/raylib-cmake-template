cmake_minimum_required(VERSION 3.24)
project(raylib-template LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Our Project
add_executable(${PROJECT_NAME})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion) # From https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_sources(${PROJECT_NAME} PRIVATE main.cpp)


# Dependencies
include(FetchContent)

set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "") # We don't want to build raylib's (or any, since this is universal) examples
FetchContent_MakeAvailable(raylib)


target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
