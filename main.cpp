#include <iostream>
#include "Maze2.cpp"

int main() {
    //reads through the file
    Maze2 maze( "/Users/jesuslongares/CLionProjects/Maze2/maze3_input.txt");
    //prints the file
    maze.printMaze();
    maze.getStart();
    maze.getEnd();
    maze.solveMaze();

    return 0;
}
