cmake_minimum_required(VERSION 3.17.3)
project(imguiTask)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

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
        includes/ImGUI
        includes/GL
        includes/KHR
        includes/GLFW
        )

target_link_directories(${PROJECT_NAME}
        PUBLIC libs)

target_link_libraries(${PROJECT_NAME} opengl32 glfw3 user32 kernel32 gdi32)