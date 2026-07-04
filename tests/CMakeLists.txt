set(TESTS_NAME unit_tests)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.15.1 #released on 14/06/2026
)
FetchContent_MakeAvailable(Catch2)

add_executable(${TESTS_NAME}
        example_tests.cpp
)

set_target_properties(${TESTS_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        COMPILE_WARNING_AS_ERROR ON) # Treat warning as errors! Same as "-Werror"

target_compile_features(${TESTS_NAME} PRIVATE ${CPP_VERSION})
target_compile_options(${PROJECT_NAME} PRIVATE ${W_FLAGS})

# Adding the resources' folder.
add_custom_target(copy_resources_tests
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        ${CMAKE_CURRENT_LIST_DIR}/../src/resources
        $<TARGET_FILE_DIR:${TESTS_NAME}>/resources #copy to the same place as the test executable
)
add_dependencies(${TESTS_NAME} copy_resources_tests)

target_link_libraries(${TESTS_NAME}
        PRIVATE
        ${PROJECT_NAME}
        Catch2::Catch2WithMain)

#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(${TESTS_NAME})