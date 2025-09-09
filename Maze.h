//
// Created by Jesus Longares on 9/8/25.
//Here it will create the read the file and create the grid of the maze.
//It will also locate and return the start and end

#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



class Maze {
  public:
    //constructor
    Maze( string fileName );
    //prints the maze
    void printMaze();
  //prints location of where start and end
  void getStart();
  void getEnd();



  private:
    vector<tuple<int, int, int>> maze;//in here you place the value tuple

  //special case variables
    tuple<int, int, int> start;
    tuple<int, int, int> end;
    int maxRows;
    int maxCols;
    //helper functions
    void findStart();
    void findEnd();


};



#endif //MAZE_H
