# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/milosz/CppProjects/MazeProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/milosz/CppProjects/MazeProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MazeProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MazeProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MazeProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MazeProject.dir/flags.make

CMakeFiles/MazeProject.dir/maze1.cpp.o: CMakeFiles/MazeProject.dir/flags.make
CMakeFiles/MazeProject.dir/maze1.cpp.o: ../maze1.cpp
CMakeFiles/MazeProject.dir/maze1.cpp.o: CMakeFiles/MazeProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MazeProject.dir/maze1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeProject.dir/maze1.cpp.o -MF CMakeFiles/MazeProject.dir/maze1.cpp.o.d -o CMakeFiles/MazeProject.dir/maze1.cpp.o -c /home/milosz/CppProjects/MazeProject/maze1.cpp

CMakeFiles/MazeProject.dir/maze1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeProject.dir/maze1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/milosz/CppProjects/MazeProject/maze1.cpp > CMakeFiles/MazeProject.dir/maze1.cpp.i

CMakeFiles/MazeProject.dir/maze1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeProject.dir/maze1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/milosz/CppProjects/MazeProject/maze1.cpp -o CMakeFiles/MazeProject.dir/maze1.cpp.s

CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o: CMakeFiles/MazeProject.dir/flags.make
CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o: ../src/MazeSolver/maze_solver.cpp
CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o: CMakeFiles/MazeProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o -MF CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o.d -o CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o -c /home/milosz/CppProjects/MazeProject/src/MazeSolver/maze_solver.cpp

CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/milosz/CppProjects/MazeProject/src/MazeSolver/maze_solver.cpp > CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.i

CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/milosz/CppProjects/MazeProject/src/MazeSolver/maze_solver.cpp -o CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.s

CMakeFiles/MazeProject.dir/src/main.cpp.o: CMakeFiles/MazeProject.dir/flags.make
CMakeFiles/MazeProject.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/MazeProject.dir/src/main.cpp.o: CMakeFiles/MazeProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MazeProject.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeProject.dir/src/main.cpp.o -MF CMakeFiles/MazeProject.dir/src/main.cpp.o.d -o CMakeFiles/MazeProject.dir/src/main.cpp.o -c /home/milosz/CppProjects/MazeProject/src/main.cpp

CMakeFiles/MazeProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/milosz/CppProjects/MazeProject/src/main.cpp > CMakeFiles/MazeProject.dir/src/main.cpp.i

CMakeFiles/MazeProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/milosz/CppProjects/MazeProject/src/main.cpp -o CMakeFiles/MazeProject.dir/src/main.cpp.s

CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o: CMakeFiles/MazeProject.dir/flags.make
CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o: ../src/Maze/Maze.cpp
CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o: CMakeFiles/MazeProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o -MF CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o.d -o CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o -c /home/milosz/CppProjects/MazeProject/src/Maze/Maze.cpp

CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/milosz/CppProjects/MazeProject/src/Maze/Maze.cpp > CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.i

CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/milosz/CppProjects/MazeProject/src/Maze/Maze.cpp -o CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.s

CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o: CMakeFiles/MazeProject.dir/flags.make
CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o: ../src/Maze_generator/maze_generator.cpp
CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o: CMakeFiles/MazeProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o -MF CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o.d -o CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o -c /home/milosz/CppProjects/MazeProject/src/Maze_generator/maze_generator.cpp

CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/milosz/CppProjects/MazeProject/src/Maze_generator/maze_generator.cpp > CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.i

CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/milosz/CppProjects/MazeProject/src/Maze_generator/maze_generator.cpp -o CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.s

# Object files for target MazeProject
MazeProject_OBJECTS = \
"CMakeFiles/MazeProject.dir/maze1.cpp.o" \
"CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o" \
"CMakeFiles/MazeProject.dir/src/main.cpp.o" \
"CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o" \
"CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o"

# External object files for target MazeProject
MazeProject_EXTERNAL_OBJECTS =

MazeProject: CMakeFiles/MazeProject.dir/maze1.cpp.o
MazeProject: CMakeFiles/MazeProject.dir/src/MazeSolver/maze_solver.cpp.o
MazeProject: CMakeFiles/MazeProject.dir/src/main.cpp.o
MazeProject: CMakeFiles/MazeProject.dir/src/Maze/Maze.cpp.o
MazeProject: CMakeFiles/MazeProject.dir/src/Maze_generator/maze_generator.cpp.o
MazeProject: CMakeFiles/MazeProject.dir/build.make
MazeProject: CMakeFiles/MazeProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MazeProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MazeProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MazeProject.dir/build: MazeProject
.PHONY : CMakeFiles/MazeProject.dir/build

CMakeFiles/MazeProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MazeProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MazeProject.dir/clean

CMakeFiles/MazeProject.dir/depend:
	cd /home/milosz/CppProjects/MazeProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/milosz/CppProjects/MazeProject /home/milosz/CppProjects/MazeProject /home/milosz/CppProjects/MazeProject/cmake-build-debug /home/milosz/CppProjects/MazeProject/cmake-build-debug /home/milosz/CppProjects/MazeProject/cmake-build-debug/CMakeFiles/MazeProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MazeProject.dir/depend

