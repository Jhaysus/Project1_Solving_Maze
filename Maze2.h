//
// Created by Jesus Longares on 9/8/25.
//

#ifndef MAZE2_H
#define MAZE2_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


class Maze2 {
  public:
    Maze2( string fileName );
    //prints the maze
    void printMaze();
    //prints location of where start and end
    void getStart();
    void getEnd();
    void solveMaze();

    private:
      vector<vector<int> > maze; //in here you place the values

      tuple<int, int, int>start;
      tuple<int, int, int>end;

      int maxRows, maxCols;
      void findStart();
      void findEnd();


};



#endif //MAZE2_H
