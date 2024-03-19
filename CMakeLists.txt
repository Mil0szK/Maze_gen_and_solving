cmake_minimum_required(VERSION 3.22)
project(MazeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MazeProject
        maze1.cpp
        src/MazeSolver/maze_solver.cpp
        src/main.cpp
        src/Maze/Maze.cpp
        src/Maze/Maze.h
        src/MazeSolver/maze_solver.h
        src/Maze_generator/maze_generator.cpp
        src/Maze_generator/maze_generator.h
)
