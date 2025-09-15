#include <iostream>
#include "Maze2.cpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
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

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.