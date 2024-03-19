#include "Maze.h"
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>
#include <future>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstdio>

bool Cell::operator<(const Cell& other) const {
    if (x == other.x) {
        return y < other.y;
    }
    return x < other.x;
}



Maze::Maze(int width, int height) : width(width), height(height), grid(height, std::vector<Cell>(width)) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = {x, y, Blocked};
        }
    }
}

void Maze::connect_cells(Cell& cell1, Cell& cell2) {
    int x = (cell1.x + cell2.x) / 2;
    int y = (cell1.y + cell2.y) / 2;
    grid[cell1.y][cell1.x].state = Passage;
    grid[y][x].state = Passage;
}

std::set<Cell> Maze::frontier(int x, int y) {
    std::set<Cell> frontiers;
    if (x > 2 && grid[y][x - 2].state == Blocked) {
        frontiers.insert(grid[y][x - 2]);
    }
    if (x + 2 < width - 1 && grid[y][x + 2].state == Blocked) {
        frontiers.insert(grid[y][x + 2]);
    }
    if (y > 2 && grid[y - 2][x].state == Blocked) {
        frontiers.insert(grid[y - 2][x]);
    }
    if (y + 2 < height - 1 && grid[y + 2][x].state == Blocked) {
        frontiers.insert(grid[y + 2][x]);
    }
    return frontiers;
}

std::set<Cell> Maze::neighbours(int x, int y) {
    std::set<Cell> neighbours;
    if (x > 2 && grid[y][x - 2].state == Passage) {
        neighbours.insert(grid[y][x - 2]);
    }
    if (x + 2 < width - 1 && grid[y][x + 2].state == Passage) {
        neighbours.insert(grid[y][x + 2]);
    }
    if (y > 2 && grid[y - 2][x].state == Passage) {
        neighbours.insert(grid[y - 2][x]);
    }
    if (y + 2 < height - 1 && grid[y + 2][x].state == Passage) {
        neighbours.insert(grid[y + 2][x]);
    }
    return neighbours;
}
void Maze::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(10, width - 5); // distribution for x
    std::uniform_int_distribution<> disY(10, height - 5); // distribution for y

    int x = disX(gen);
    int y = disY(gen);

    grid[y][x].state = Passage;

    auto f = frontier(x, y);
    std::uniform_int_distribution<> disF(0, f.size() - 1);

    while (!f.empty()) {
        auto it = f.begin();
        std::advance(it, disF(gen));
        auto current = *it;
        f.erase(it);
        auto n = neighbours(current.x, current.y);
        std::uniform_int_distribution<> disN(0, n.size() - 1); // distribution for neighbours

        if (!n.empty()) {
            auto it = n.begin();
            std::advance(it, disN(gen));

            auto next = *it;
            connect_cells(current, next);
        }
        auto current_frontier = frontier(current.x, current.y);
        f.insert(current_frontier.begin(), current_frontier.end());
        disF = std::uniform_int_distribution<>(0, f.size() - 1); // update the distribution for frontiers
    }
};

Cell Maze::findStartCell() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x].state == Passage) {
                return grid[y][x];
            }
        }
    }
    return {-1, -1, Blocked};
}

Cell Maze::findEscapeCell() {
    for (int y = height - 1; y >= 0; --y) {
        for (int x = width - 1; x >= 0; x--) {
            if (grid[y][x].state == Passage) {
                return grid[y][x];
            }
        }
    }
    return {-1, -1, Blocked};
}

void Maze::print(std::ostream& os) {
    Cell startCell = findStartCell();
    Cell escapeCell = findEscapeCell();
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == startCell) {
                os << 'S';
            } else if (cell == escapeCell) {
                os << 'E';
            } else if (cell.state == Blocked) {
                os << '#';
            } else {
                os << ' ';
            }
        }
        os << '\n';
    }
}

//void mainly() {
//    while (true) {
//        // Create a Maze object and generate a maze
//        Maze maze(40, 40);
//        maze.generate();
//
//        // Print the maze to a file
//        FILE* fp = freopen("output.txt", "w", stdout);
//        if (fp == NULL) {
//            perror("Error opening file");
//            return 1;
//        }
//        maze.print();
//        fclose(stdout);
//
//
//        // Wait for 2 seconds
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//
//        // Open the output file
//        FILE* file = std::fopen("output.txt", "r");
//        if (!file) {
//            std::perror("Failed to open output file");
//            exit(1);
//        }
//
//
//        // Check if the output file is empty
//        std::fseek(file, 0, SEEK_END);
//        long size = std::ftell(file);
//        std::fclose(file);
//
//        if (size == 0) {
//            // If the output file is empty, try again
//            std::cout << "Maze generation took too long. Trying again..." << std::endl;
//        } else {
//            // If the output file is not empty, break the loop
//            break;
//        }
//    }
//    return 0;
//}