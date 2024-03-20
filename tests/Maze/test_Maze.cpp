#include "gtest/gtest.h"
#include "../../src/Maze/Maze.h"

TEST(MazeTest, Constructor) {
    Maze maze(10, 10);
    EXPECT_EQ(maze.getWidth(), 10);
    EXPECT_EQ(maze.getHeight(), 10);
}

TEST(MazeTest, Frontier) {
    Maze maze(10, 10);

    std::set<Cell> expectedFrontiers;
    expectedFrontiers.insert({3, 5, Blocked});
    expectedFrontiers.insert({7, 5, Blocked});
    expectedFrontiers.insert({5, 3, Blocked});
    expectedFrontiers.insert({5, 7, Blocked});

    std::set<Cell> frontiers = maze.frontier(5, 5);

    EXPECT_EQ(frontiers, expectedFrontiers);

}

TEST(MazeTest, Neighbours) {
    Maze maze(10, 10);
    maze.connect_cells(maze.getCell(5, 3), maze.getCell(5, 5));
    maze.connect_cells(maze.getCell(5, 7), maze.getCell(5, 5));
    maze.connect_cells(maze.getCell(3, 5), maze.getCell(5, 5));
    maze.connect_cells(maze.getCell(7, 5), maze.getCell(5, 5));

    std::set<Cell> expected_neighbours;
    expected_neighbours.insert(maze.getCell(5, 3));
    expected_neighbours.insert(maze.getCell(5, 7));
    expected_neighbours.insert(maze.getCell(3, 5));
    expected_neighbours.insert(maze.getCell(7, 5));

    std::set<Cell> neighbours = maze.neighbours(5, 5);
    EXPECT_EQ(neighbours, expected_neighbours);
}