#ifndef MAZE_H
#define MAZE_H

#include <set>
#include <vector>
#include <iostream>

// Define the states a cell can be in
enum State {Blocked, Passage};

// Define the structure of a cell
struct Cell {
    int x, y; // The coordinates of the cell

    State state; // The state of the cell (either Blocked or Passage)

    // Default constructor
    Cell() : x(0), y(0), state(Blocked) {}

    Cell(int x, int y, State state) : x(x), y(y), state(state) {}

    // Overload the less-than operator to compare cells based on their coordinates
    bool operator<(const Cell& other) const;

    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y && state == other.state;
    }
};

// Define the Maze class
class Maze {
public:
    // Constructor for the Maze class
    Maze(int width, int height);

    // Connect two cells by setting the cell in between them to Passage
    void connect_cells(Cell& cell1, Cell& cell2);

    // Return the frontier cells of a given cell
    std::set<Cell> frontier(int x, int y);

    // Return the neighbouring cells of a given cell
    std::set<Cell> neighbours(int x, int y);

    // Generate the maze using Prim's algorithm
    void generate();

    // Find the start cell of the maze
    Cell findStartCell();

    // Find the escape cell of the maze
    Cell findEscapeCell();

    // get a cell from the grid
    Cell& getCell(int x, int y) {
        return grid[y][x];
    }

    // set a cell in the grid
    void setCell(int x, int y, const Cell& cell) {
        grid[y][x] = cell;
    }

    // Print the maze
    void print(std::ostream& os);

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width; // The width of the maze
    int height; // The height of the maze
    std::vector<std::vector<Cell>> grid; // The grid of cells

};

void mainly();

#endif // MAZE_H