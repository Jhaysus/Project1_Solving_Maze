//
// Created by Jesus Longares on 9/8/25.
//

#include "Maze.h"
//I want to be able to go through the file and save everything into the vector of tuples
Maze::Maze(string fileName) {
  ifstream file(fileName);
  string line;
  int row = 0;

  tuple<int, int, int> cell;

  if (!file) {
    cout<<"Error file does not exist"<<endl;
  }
  //Big O(N^2)
  while (getline(file, line)) {
    maxCols = line.length();
    for( int col = 0; col < line.length(); col++){
      if( line.at(col) ==  '1'){// check if wall
        cell = tuple<int, int, int>(row, col, 1);
      }
      if( line.at(col) ==  '0'){ //checks open
        cell = tuple<int, int, int>(row, col, 0);
      }
      //add to the vector
     maze.push_back(cell);
    }
    //after each line increment row
    row++;
  }
  maxRows = row;
  file.close();
}

void Maze::printMaze() {
  if(maze.size() == 0){
    cout<<"Maze is empty"<<endl;
  }else{
    int index = 0;
    while(maze.size() > index){
      if(get<0>(maze[index]) < get<0>(maze[index+1]) ) {
        if (get<2>(maze[index]) == 0) {
          cout<<"*"<<"\n";
        }else{
        cout<<get<2>(maze[index])<<"\n";
        }
      }else{
        if (get<2>(maze[index]) == 0) {
          cout<<"*"<<"";
        }else {
          cout<<get<2>(maze[index])<<"";
        }
       }
     index++;
    }
  }
  cout<<"\n\n\t\t  Maze size\n\t  Rows:"<<maxRows <<" Col: "<< maxCols<<endl;


}

void Maze::findStart() {
  if (maze.empty()) {
    cout<<"Maze is empty"<<endl;

  }else {
    int index = 0;
    while(maze.size() > index) {
      auto cellHolder = maze[index];
      if (get<2>(cellHolder) != 0) {
        index++;

      }else{
        //top row, all the columns
        if (get<0>(cellHolder) == 0)  {
          start = cellHolder;
          return;

        }//left side, column 0, row all numbers
        if (get<1>(cellHolder) == 0) {
          start = cellHolder;
          return;
        }
        //bottom row
        if (get<0>(cellHolder) == maxRows-1)  {
          start = cellHolder;
          return;

        }
        //right side, column is max number of columns, row all numbers
        if (get<1>(cellHolder) == maxCols-1) {
          start = cellHolder;
          return;
        }
        index++;

      }
    }
  }
}

void Maze::getStart() {
  findStart();
  cout<<"\n\t Start of maze: ("<< get<0>(start)<<","<<get<1>(start)<<")"<<endl;

}

void Maze::findEnd() {
  if (maze.empty()) {
    cout<<"Maze is empty"<<endl;

  }else {
    int index = 0;
    while(maze.size() > index) {
      auto cellHolder = maze[index];
      if (get<2>(cellHolder) != 0) {
        index++;

      }else{
        //make sure values don't match to start. You already determined where to start, no repeats
        if (cellHolder != start) {

          //top row, all the columns
          if (get<0>(cellHolder) == 0)  {
            end = cellHolder;
            return;

          }//left side, column 0, row all numbers
          if (get<1>(cellHolder) == 0) {
            end = cellHolder;
            return;
          }
          //bottom row
          if (get<0>(cellHolder) == maxRows-1)  {
            end = cellHolder;
            return;

          }
          //right side, column is max number of columns, row all numbers
          if (get<1>(cellHolder) == maxCols-1) {
            end = cellHolder;
            return;
          }

          index++;

        }else {
          index++;
        }
      }
    }
  }
}

void Maze::getEnd() {
  findEnd();
  //0 based starting point. Makes last column and row at 0
  cout<<"\n\t End of maze: ("<< get<0>(end)<<","<<get<1>(end)<<")"<<endl;

}
