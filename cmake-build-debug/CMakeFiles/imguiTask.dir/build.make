# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Foxx\CLionProjects\untitled1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/imguiTask.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imguiTask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imguiTask.dir/flags.make

CMakeFiles/imguiTask.dir/src/gl3w.c.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/gl3w.c.obj: CMakeFiles/imguiTask.dir/includes_C.rsp
CMakeFiles/imguiTask.dir/src/gl3w.c.obj: ../src/gl3w.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/imguiTask.dir/src/gl3w.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\imguiTask.dir\src\gl3w.c.obj   -c C:\Users\Foxx\CLionProjects\untitled1\src\gl3w.c

CMakeFiles/imguiTask.dir/src/gl3w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imguiTask.dir/src/gl3w.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\gl3w.c > CMakeFiles\imguiTask.dir\src\gl3w.c.i

CMakeFiles/imguiTask.dir/src/gl3w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imguiTask.dir/src/gl3w.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\gl3w.c -o CMakeFiles\imguiTask.dir\src\gl3w.c.s

CMakeFiles/imguiTask.dir/src/main.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/main.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/imguiTask.dir/src/main.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\main.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\main.cpp

CMakeFiles/imguiTask.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\main.cpp > CMakeFiles\imguiTask.dir\src\main.cpp.i

CMakeFiles/imguiTask.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\main.cpp -o CMakeFiles\imguiTask.dir\src\main.cpp.s

CMakeFiles/imguiTask.dir/src/imgui.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui.cpp.obj: ../src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui.cpp

CMakeFiles/imguiTask.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui.cpp > CMakeFiles\imguiTask.dir\src\imgui.cpp.i

CMakeFiles/imguiTask.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui.cpp -o CMakeFiles\imguiTask.dir\src\imgui.cpp.s

CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj: ../src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui_draw.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui_draw.cpp

CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui_draw.cpp > CMakeFiles\imguiTask.dir\src\imgui_draw.cpp.i

CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui_draw.cpp -o CMakeFiles\imguiTask.dir\src\imgui_draw.cpp.s

CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj: ../src/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui_impl_glfw.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_glfw.cpp

CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_glfw.cpp > CMakeFiles\imguiTask.dir\src\imgui_impl_glfw.cpp.i

CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_glfw.cpp -o CMakeFiles\imguiTask.dir\src\imgui_impl_glfw.cpp.s

CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj: ../src/imgui_tables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui_tables.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui_tables.cpp

CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui_tables.cpp > CMakeFiles\imguiTask.dir\src\imgui_tables.cpp.i

CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui_tables.cpp -o CMakeFiles\imguiTask.dir\src\imgui_tables.cpp.s

CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj: ../src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui_widgets.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui_widgets.cpp

CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui_widgets.cpp > CMakeFiles\imguiTask.dir\src\imgui_widgets.cpp.i

CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui_widgets.cpp -o CMakeFiles\imguiTask.dir\src\imgui_widgets.cpp.s

CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj: CMakeFiles/imguiTask.dir/flags.make
CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj: CMakeFiles/imguiTask.dir/includes_CXX.rsp
CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj: ../src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imguiTask.dir\src\imgui_impl_opengl3.cpp.obj -c C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_opengl3.cpp

CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_opengl3.cpp > CMakeFiles\imguiTask.dir\src\imgui_impl_opengl3.cpp.i

CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Foxx\CLionProjects\untitled1\src\imgui_impl_opengl3.cpp -o CMakeFiles\imguiTask.dir\src\imgui_impl_opengl3.cpp.s

# Object files for target imguiTask
imguiTask_OBJECTS = \
"CMakeFiles/imguiTask.dir/src/gl3w.c.obj" \
"CMakeFiles/imguiTask.dir/src/main.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj" \
"CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj"

# External object files for target imguiTask
imguiTask_EXTERNAL_OBJECTS =

imguiTask.exe: CMakeFiles/imguiTask.dir/src/gl3w.c.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/main.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui_draw.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui_impl_glfw.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui_tables.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui_widgets.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/src/imgui_impl_opengl3.cpp.obj
imguiTask.exe: CMakeFiles/imguiTask.dir/build.make
imguiTask.exe: CMakeFiles/imguiTask.dir/linklibs.rsp
imguiTask.exe: CMakeFiles/imguiTask.dir/objects1.rsp
imguiTask.exe: CMakeFiles/imguiTask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable imguiTask.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\imguiTask.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imguiTask.dir/build: imguiTask.exe

.PHONY : CMakeFiles/imguiTask.dir/build

CMakeFiles/imguiTask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\imguiTask.dir\cmake_clean.cmake
.PHONY : CMakeFiles/imguiTask.dir/clean

CMakeFiles/imguiTask.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Foxx\CLionProjects\untitled1 C:\Users\Foxx\CLionProjects\untitled1 C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug C:\Users\Foxx\CLionProjects\untitled1\cmake-build-debug\CMakeFiles\imguiTask.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imguiTask.dir/depend

