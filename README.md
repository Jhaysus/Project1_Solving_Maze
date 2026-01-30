Dictionary Benchmark
## Student infromation:
- Jesus Longares
- Id: 008685606
- https://github.com/Jhaysus/Project1_Solving_Maze.git
## Collaboration & Sources
- Partner: None
- Sources:
    - I used chatgpt to help create the mazes to test out my methods
    - https://en.cppreference.com/w/cpp/utility/tuple.html
    - https://stackoverflow.com/questions/58375722/how-to-get-the-elements-of-a-tuple

## Implementation Details:

- In Maze2
  - Maze constructor 
    1. It takes the file and reads each line to input a value for position in which the [row][column]. It also saves the max row and col
  - Print maze 
    - 2 for loops are created to read the position of the 1 and 0. if zero, make it turn red
    - prints out the sizing of the maze
  - Get Start
    - uses a helper function( findStart) to print out where in the maze it should begin
    - findStart looks at the borders of the maze. Saves the position
  - Get End
    - uses a helper function( findEnd) to print out where in the maze it should end
    - findEnd looks at the borders of the maze. Saves the position. Since start was already found first, it just skips that positon and continues searching
  -  Solve maze
     1. Start of cell is pushed into a stack
     2. a visited vector is intialized with the starting position
     3. while stack is not empty do the following
        - checks the current postion and it's adjacent cells
        - push the cell if spot is open and has not been visited
        - stop the loop once the end is found
        - the checks revolve around looking up,right,down,left
        - pop the top of the cell if it has no adjacent cells it can explore
     4. if no stack is empty, there is no path
     5. if stack is not empty, reverse the order and print the path. Green is used to identify the path to the solution
    6. Solve uses the concept of the backtracking given in the psudocode



## Instructions to run
- command to run: g++ -std=c++17 -Wall -Wextra main.cpp Maze2.cpp -o maze
- run : ./maze maze0-1_input.txt 
  - or any of the provide mazes



## Testing & Status
  - Maze constructor
    - properly reads the file and places the position in which the binary maze is given
    - the maze starts at zero and end of maze is size-1.
  - Printing Maze
    - it follows the prompt in which the walls are 1s and the option of using the space as star is utilized to identify the location.
    - the maze is printed with red stars at first to show the paths
  - Locating start/end
    - location output follows (row, col) concept and properly locates what it needs to find
    - Start is located first
    - if end continues searching for the locating if it's at the same spot as start
      - if start == end are the same, it does not stop search
    - values are saved as private variables
  - Solve Maze
    - uses the backtracking method and properly prints out the maze after all position are saved into a local variable
    - it checks up, right, down, then left
    - if adjacent cell does not exist, pop


- What it prints out, but the ReadME doesn't allow it to properly show the output
111111111111111
1*******1*****1
1*111*1*1*1*111
****1*1*1*1***1
11111*111*111*1
1*********1***1
1*1*1*111*1*111
1*1*1***1*1***1
1*1*111*1*111*1
1*1***1*1*1*1*1
1*111*111*1*1*1
1***1***1***1**
111111111111111


		  Maze size
	  Rows:13 Col: 15

	 Start of maze: (11,14)

	 End of maze: (3,0)

Moves: 38
111111111111111
1*******1*****1
1*111*1*1*1*111
****1*1*1*1***1
11111*111*111*1
1*********1***1
1*1*1*111*1*111
1*1*1***1*1***1
1*1*111*1*111*1
1*1***1*1*1*1*1
1*111*111*1*1*1
1***1***1***1**
111111111111111









