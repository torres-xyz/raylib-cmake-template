add_library(${PROJECT_NAME}
        STATIC
        main.cpp
        constants.hpp
        imgui_sidebar.cpp
        imgui_sidebar.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        COMPILE_WARNING_AS_ERROR ON) # Treat warning as errors! Same as "-Werror"
target_compile_features(${PROJECT_NAME} PRIVATE ${CPP_VERSION})
target_compile_options(${PROJECT_NAME} PRIVATE ${W_FLAGS})

#Using this to easily exclude Debug behaviours from non-debug builds
add_compile_definitions("DEBUG=$<CONFIG:Debug>")

# Adding the resources' folder.
add_custom_target(copy_resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        ${CMAKE_CURRENT_LIST_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources #copy to the same place as the executable
)
add_dependencies(${PROJECT_NAME} copy_resources)

# Dependencies
target_link_libraries(${PROJECT_NAME}
        PUBLIC # Set to public so our Tests can have access to the headers in our dependencies
        raylib_cpp
        imgui
        rlimgui
        sqlite
)

add_executable(bootstrap bootstrap-main.cpp
)
target_link_libraries(bootstrap PRIVATE ${PROJECT_NAME})