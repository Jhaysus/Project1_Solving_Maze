#include <iostream>
#include "Maze2.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

//fix to make it run on blue, in otherwords working to not hard code 
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <inputfile>\n";
        return 1;
    }
    Maze2 m(argv[1]);

    m.printMaze();
    m.getStart();
    m.getEnd();
    m.solveMaze();
}

// int main() {
//     //reads through the file
//     Maze2 maze( "/Users/jesuslongares/CLionProjects/Maze2/maze2_input.txt");
//     //prints the file
//     maze.printMaze();
//     maze.getStart();
//     maze.getEnd();
//     maze.solveMaze();

//     return 0;
// }

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.