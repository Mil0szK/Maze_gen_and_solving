NAME1 = Maze
NAME2 = maze_solver
NAME3 = main

EXEC3  = $(NAME3).x

OBJS1  = src/Maze/$(NAME1).o
OBJS2  = src/MazeSolver/$(NAME2).o
OBJS3  = src/$(NAME3).o

CFLAGS = -Wall -std=c++11 -pedantic -O -fPIC -Wno-sign-compare
LDFLAGS = -Wall -std=c++11 -pedantic -O
TEST_OBJ_FILE1 = tests/MazeSolver/$(NAME4).o
TEST_OBJ_FILE2 += tests/Maze/$(NAME5).o

CO = g++
LD = $(CO)

src/Maze/%.o: src/Maze/%.cpp
	$(CO) $(CFLAGS) -c $< -o $@

src/MazeSolver/%.o: src/MazeSolver/%.cpp
	$(CO) $(CFLAGS) -c $< -o $@

src/%.o: src/%.cpp
	$(CO) $(CFLAGS) -c $< -o $@

.PHONY: all clean run
all: $(EXEC3)

$(EXEC3): $(OBJS1) $(OBJS2) $(OBJS3)
	$(LD) -o $@ $(LDFLAGS) $^

run: all
	./$(EXEC3)

clean:
	rm src/Maze/*.o
	rm src/MazeSolver/*.o
	rm src/*.o $(EXEC3)