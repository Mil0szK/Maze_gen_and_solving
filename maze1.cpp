#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>

// Define the states a cell can be in
enum State {Blocked, Passage};

// Define the structure of a cell
struct Cell {
    int x, y; // The coordinates of the cell
    State state; // The state of the cell (either Blocked or Passage)

    // Overload the less-than operator to compare cells based on their coordinates
    bool operator<(const Cell& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

// Define the Maze class
class Maze {
public:
    // Constructor for the Maze class
    Maze(int width, int height) : width(width), height(height), grid(height, std::vector<Cell>(width)) {
        // Initialize all cells to Blocked
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = {x, y, Blocked};
            }
        }
    }

    // Connect two cells by setting the cell in between them to Passage
    void connect_cells(Cell& cell1, Cell& cell2) {
        int x = (cell1.x + cell2.x) / 2;
        int y = (cell1.y + cell2.y) / 2;
        grid[cell1.y][cell1.x].state = Passage;
        grid[y][x].state = Passage;
    }

    // Return the frontier cells of a given cell
    std::set<Cell> frontier(int x, int y) {
        std::set<Cell> frontiers;
        // Check the four directions (up, down, left, right) for frontier cells
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

    // Return the neighbouring cells of a given cell
    std::set<Cell> neighbours(int x, int y) {
        std::set<Cell> neighbours;
        // Check the four directions (up, down, left, right) for neighbouring cells
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

// Generate the maze using Prim's algorithm
void generate() {
    std::random_device rd; // Create a random device
    std::mt19937 gen(rd()); // Create a random number generator
    std::uniform_int_distribution<> dis(0, width - 1); // Create a uniform distribution
    int x = dis(gen); // Generate a random x-coordinate
    int y = dis(gen); // Generate a random y-coordinate
    grid[y][x].state = Passage; // Set the state of the cell at (x, y) to Passage
    auto f = frontier(x, y); // Get the frontier cells of the cell at (x, y)
    // While there are still frontier cells
    while (!f.empty()) {
        auto it = f.begin(); // Get an iterator to the beginning of the set of frontier cells
        std::advance(it, dis(gen) % f.size()); // Advance the iterator a random number of steps
        auto current = *it; // Get the current cell
        f.erase(it); // Remove the current cell from the set of frontier cells
        auto n = neighbours(current.x, current.y); // Get the neighbours of the current cell
        // If the current cell has neighbours
        if (!n.empty()) {
            auto it = n.begin(); // Get an iterator to the beginning of the set of neighbours
            std::advance(it, dis(gen) % n.size()); // Advance the iterator a random number of steps
            auto next = *it; // Get the next cell
            connect_cells(current, next); // Connect the current cell and the next cell
        }
        auto current_frontier = frontier(current.x, current.y); // Get the frontier cells of the current cell
        f.insert(current_frontier.begin(), current_frontier.end()); // Add the frontier cells to the set of frontier cells
    }
}

    // Find the start cell of the maze
    Cell findStartCell() {
        // Iterate over the rows of the grid
        for (int y = 0; y < height; ++y) {
            // Iterate over the cells in a row
            for (int x = 0; x < width; x++) {
                // If the state of the cell is Passage, return the cell
                if (grid[y][x].state == Passage) {
                    return grid[y][x];
                }
            }
        }
        // If no start cell is found, return a blocked cell
        return {-1, -1, Blocked};
    }

    // Find the escape cell of the maze
    Cell findEscapeCell() {
        // Iterate over the rows of the grid in reverse order
        for (int y = height - 1; y >= 0; --y) {
            // Iterate over the cells in a row in reverse order
            for (int x = width - 1; x >= 0; x--) {
                // If the state of the cell is Passage, return the cell
                if (grid[y][x].state == Passage) {
                    return grid[y][x];
                }
            }
        }
        // If no escape cell is found, return a blocked cell
        return {-1, -1, Blocked};
    }

    // Print the maze
    void print() {
        Cell startCell = findStartCell(); // Find the start cell
        Cell escapeCell = findEscapeCell(); // Find the escape cell

        // Iterate over the rows of the grid
        for (const auto& row : grid) {
            // Iterate over the cells in a row
            for (const auto& cell : row) {
                // If the cell is the start cell, print 'S'
                if (cell.x == startCell.x && cell.y == startCell.y) {
                    std::cout << "S";
                }
                    // If the cell is the escape cell, print 'E'
                else if (cell.x == escapeCell.x && cell.y == escapeCell.y) {
                    std::cout << "E";
                }
                    // If the cell is a passage, print '  '
                else {
                    std::cout << (cell.state == Passage ? "  " : "##");
                }
            }
            std::cout << "\n"; // Print a newline character at the end of each row
        }
    }

private:
    std::vector<std::vector<Cell>> grid; // The grid of cells
    int width; // The width of the maze
    int height; // The height of the maze
};

// The main function
int main() {
    Maze maze(40, 40); // Create a maze with a width and height of 40
    maze.generate(); // Generate the maze

    maze.print(); // Print the maze

    return 0; // Return 0 to indicate that the program has finished successfully
}