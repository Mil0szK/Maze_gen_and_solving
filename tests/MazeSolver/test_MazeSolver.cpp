#include "gtest/gtest.h"
#include <fstream>
#include "../../src/MazeSolver/maze_solver.h"

TEST(MazeSolverTest, Solve) {
    std::ifstream inputFile("test_output.txt");
    std::vector<std::string> maze;
    std::string line;
    while (std::getline(inputFile, line)) {
        maze.push_back(line);
    }
    inputFile.close();

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

    std::vector<std::string> result = aStar(maze, start, end);

    // Read expected result from file
    std::ifstream expectedFile("test_result.txt");
    std::vector<std::string> expected_result;
    while (std::getline(expectedFile, line)) {
        expected_result.push_back(line);
    }
    expectedFile.close();

    EXPECT_EQ(result, expected_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}