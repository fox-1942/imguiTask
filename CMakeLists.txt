cmake_minimum_required(VERSION 3.17.3)
project(imguiTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        src/gl3w.c
        src/init.cpp
        src/imgui.cpp
        src/imgui_draw.cpp
        src/imgui_impl_glfw.cpp
        src/imgui_tables.cpp
        src/imgui_widgets.cpp
        src/imgui_impl_opengl3.cpp
        src/ImGuiFileBrowser.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        includes
        includes/GLFW
        includes/ImGUI
        includes/GL
        includes/KHR
        )

target_link_directories(${PROJECT_NAME} PUBLIC libs/GLFW libs/Dirent)

target_link_libraries(${PROJECT_NAME} opengl32 glfw3)