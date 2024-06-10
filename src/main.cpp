#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include "MazeSolver/maze_solver.h" // Include the MazeSolver header file
#include "Maze/Maze.h" // Include the MazeGenerator header file


int main() {

    int width, height;
    std::cout << "Give width of maze (min 15): \n";
    std::cin >> width;
    std::cout << "Give height of maze (min 15): \n";
    std::cin >> height;

    Maze maze1(width, height);

    maze1.generate(); // Generate the maze


    maze1.print(std::cout);

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Failed to open output file for writing\n";
        return 1;
    }

    // Print the maze to the file
    maze1.print(outputFile);
    outputFile.close();



    // Read the maze from output.txt
    std::ifstream inputFile("output.txt");
    std::vector<std::string> maze;
    std::string line;
    while (std::getline(inputFile, line)) {
        maze.push_back(line);
    }
    inputFile.close();

    // Find the start and end points
    Point start(-1, -1), end(-1, -1);
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j] == 'S') {
                start.x = i;
                start.y = j;
            } else if (maze[i][j] == 'E') {
                end.x = i;
                end.y = j;
            }
        }
    }
    // Check if the maze is empty
    if (maze.empty()) {
        std::cerr << "Maze is empty\n";
        return 1;
    }
// Check if the start and end points are valid
    if (start.x == -1 || start.y == -1 || end.x == -1 || end.y == -1) {
        std::cerr << "Start or end point is not set\n";
        return 1;
    }

    // Solve the maze
    aStar(maze, start, end);


    return 0;
}