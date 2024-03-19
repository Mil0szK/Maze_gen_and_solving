#include "maze_solver.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>


Point::Point() : x(0), y(0), f(0), g(0), h(0) {}
Point::Point(int x, int y) : x(x), y(y), f(0), g(0), h(0) {}

bool Point::operator<(const Point& other) const {
    return f > other.f;
}

bool isValid(int x, int y, const std::vector<std::string>& maze, const std::vector<std::vector<bool>>& closedSet) {
    return x >= 0 && x < closedSet.size() && y >= 0 && y < closedSet[0].size() && maze[x][y] != '#';
}

double heuristic(int x, int y, const Point& end) {
    return sqrt(pow(x - end.x, 2) + pow(y - end.y, 2));
}

void printMaze(const std::vector<std::string>& maze) {
    for (const std::string& row : maze) {
        std::cout << row << std::endl;
    }
}

std::vector<std::string> aStar(const std::vector<std::string>& maze, Point start, Point end) {
    std::priority_queue<Point> openSet;
    std::vector<std::vector<bool>> closedSet(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<std::vector<Point>> cameFrom(maze.size(), std::vector<Point>(maze[0].size()));

    start.h = heuristic(start.x, start.y, end);
    openSet.push(start);

    while (!openSet.empty()) {
        Point current = openSet.top();
        openSet.pop();

        if (current.x == end.x && current.y == end.y) {
            std::cout << "Path found!\n";
            std::vector<Point> path;
            while (!(current.x == start.x && current.y == start.y)) {
                path.push_back(current);
                if (current.x < 0 || current.x >= cameFrom.size() || current.y < 0 || current.y >= cameFrom[0].size()) {
                    std::cerr << "Invalid index in cameFrom: " << current.x << ", " << current.y << std::endl;
                    break;
                }
                current = cameFrom[current.x][current.y];
            }
            path.push_back(start);

            std::vector<std::string> mazeCopy = maze;
            for (int i = 1; i < path.size() - 1; ++i) {
                mazeCopy[path[i].x][path[i].y] = '*';
            }
            for (const std::string& row : mazeCopy) {
                std::cout << row << std::endl;
            }
            return mazeCopy;
        }

        closedSet[current.x][current.y] = true;

        std::vector<int> dx = {-1, 0, 1, 0};
        std::vector<int> dy = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isValid(nx, ny, maze, closedSet) && !closedSet[nx][ny]) {
                double tentative_g = current.g + 1;

                Point neighbor(nx, ny);
                if (tentative_g < neighbor.g || !neighbor.g) {
                    neighbor.g = tentative_g;
                    neighbor.h = heuristic(nx, ny, end);
                    neighbor.f = neighbor.g + neighbor.h;
                    openSet.push(neighbor);
                    cameFrom[nx][ny] = current;
                }
            }
        }
    }

    std::cout << "Path not found!\n";
    return maze; // return the original maze if no path is found
}