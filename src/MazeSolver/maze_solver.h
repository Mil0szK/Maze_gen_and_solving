#ifndef MAZEPROJECT_MAZE_SOLVER_H
#define MAZEPROJECT_MAZE_SOLVER_H

#include <vector>
#include <string>

// Define a structure for points in the maze
struct Point {
    int x, y; // The x and y coordinates of the point
    double f, g, h; // f is the total cost, g is the distance from the start node, h is the heuristic value

    // Constructors
    Point();
    Point(int x, int y);

    // Overload the less-than operator to compare points based on their f values
    bool operator<(const Point& other) const;
};

// Function to solve the maze using A* algorithm
std::vector<std::string> aStar(const std::vector<std::string>& maze, Point start, Point end);


#endif //MAZEPROJECT_MAZE_SOLVER_H