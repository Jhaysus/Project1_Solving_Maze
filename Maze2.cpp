//
// Created by Jesus Longares on 9/8/25.
//

#include "Maze2.h"
//I want to be able to go through the file and save everything into the vector of vectors
Maze2::Maze2(string maze_file){
    ifstream file(maze_file);
    string line;

    int row = 0;

    if(!file){
      cerr << "File not found" << endl;
    }
    while(getline(file, line)){
      vector<int> rows;
      maxCols = line.length();
      for(int col = 0; col < maxCols; col++){
        if( line.at(col) == '1'){
          rows.push_back( 1);

        }
        if( line.at(col) == '0'){
          rows.push_back(0);
        }

      }
      row++;
      maze.push_back(rows);

    }
    maxRows = row;
    file.close();
}


void Maze2::printMaze(){
  if(maze.size() == 0){
    cerr << "Maze is empty" << endl;
  }else{
    for(int row = 0; row < maxRows; row++){
      for(int col = 0; col < maxCols; col++){
        if(maze.at(row).at(col) == 0){
          cout<<"\033[31m"<<"*"<<"\033[0m";
        }
        if (maze.at(row).at(col) == 1) {
          cout<< "1";
        }
      }
      cout<<"\n";
    }
    cout<<"\n\n\t\t  Maze size\n\t  Rows:"<<maxRows <<" Col: "<< maxCols<<endl;

  }
}


void Maze2::findStart() {
  if(maze.empty()) {
    cerr << "Maze is empty" << endl;
  }else {
    for ( int row = 0; row < maxRows; row++) {
      for ( int col = 0; col < maxCols; col++) {
        if ( maze.at(row).at(col) != 0) {
          continue;

        }
          //check top row, check all columns
          if ( row == 0) {
            start = {row, col, 0};
            return;
          }
        //check left side
      if ( col == 0) {
        start = {row, col, 0};
      }
        //check right
        if ( col == maxCols - 1) {
          start = {row, col, 0};
          return;
        }
        //check bottom row
        if ( row == maxRows - 1) {
          start = {row, col, 0};
          return;
        }
      }
    }
  }
}

void Maze2::getStart() {
  findStart();
  cout<<"\n\t Start of maze: ("<< get<0>(start)<<","<<get<1>(start)<<")"<<endl;

}


void Maze2::findEnd() {
  if(maze.empty()) {
    cerr << "Maze is empty" << endl;
  }else {
    for ( int row = 0; row < maxRows; row++) {
      for ( int col = 0; col < maxCols; col++) {
        if ( maze.at(row).at(col) != 0) {
          continue;

        }
        if (row != get<0>(start) && col != get<1>(start)) {




          //check top row, check all columns
          if ( row == 0) {
            end = {row, col, 0};
            return;
          }
          //check left side
          if ( col == 0) {
            end = {row, col, 0};
          }
          //check right
          if ( col == maxCols - 1) {
            end = {row, col, 0};
            return;
          }
          //check bottom row
          if ( row == maxRows - 1) {
            end = {row, col, 0};
            return;
          }
        }
      }
    }
  }
}


void Maze2::getEnd() {
  findEnd();
  //0 based starting point. Makes last column and row at 0
  cout<<"\n\t End of maze: ("<< get<0>(end)<<","<<get<1>(end)<<")"<<endl;

}



void Maze2::solveMaze() {
  std::stack<tuple<int, int, int>> moves;
  moves.push(start);
  vector<vector<bool>> visited(maxRows, vector<bool>(maxCols, false));//sizing set
  visited[get<0>(start)][get<1>(start)] = true;
  while(!moves.empty()) {
    int row = get<0>(moves.top());
    int col = get<1>(moves.top());
    bool exploredMove = false;

    //check above the current position
    if (row > 0 ) { //make sure row does not go past
      if ( maze.at(row-1).at(col) == 0 && !visited[row-1][col]) { //if the spot on top is open and is has not been visited
        visited[row-1][col] = true;
        moves.push({row-1, col, 0});
        exploredMove = true;

        if (row-1 == get<0>(end) && col == get<1>(end)) {//stop the program once you found the end
          break;
        }
        continue;

      }
    }

      //check right
      if (col+1 < maxCols ) {
        if (maze.at(row).at(col+1) == 0 && !visited[row][col+1]) {
          visited[row][col+1] = true;
          moves.push({row, col+1, 0});
          exploredMove = true;

          if (row == get<0>(end) && col+1 == get<1>(end)) {
            break;
          }
          continue;

        }
      }
      //check down
      if (row+1 < maxRows) {
        if (maze.at(row+1).at(col) == 0 && !visited[row+1][col]) {
          visited[row+1][col] = true;
          moves.push({row+1, col, 0});
          exploredMove = true;

          if (row+1 == get<0>(end) && col == get<1>(end)) {
            break;
          }
          continue;


        }
      }

    //check left
    if ( col > 0 ) {
      if (maze.at(row).at(col-1) == 0 && !visited[row][col-1]) {
        visited[row][col-1] = true;
        moves.push({row, col-1, 0});

        exploredMove = true;

        if (row == get<0>(end) && col-1 == get<1>(end)) {
          break;
        }
        continue;
      }
    }



    //pop the top since cell has no unexplored adjacent cell
    if ( !exploredMove) {
      moves.pop();
    }

  }

  if (moves.empty()) {
    cout<<"\n No moves to solve." << endl;
  } else {
    cout<<"\n Moves: "<<moves.size()-1<<endl;
    std::stack<tuple<int, int, int>> reversed  = moves;
    std::vector<std::vector<bool>> onPath(maxRows, std::vector<bool>(maxCols, false));
  //reverse order
    while (!reversed.empty()) {
      int r = get<0>(reversed.top());
      int c = get<1>(reversed.top());
      onPath[r][c] = true;
      reversed.pop();
    }

    //print the solved
    for (int r = 0; r < maxRows; r++) {
      for (int c = 0; c < maxCols; c++) {
        if (maze[r][c] == 1) {
          std::cout << "1";
        } else if (onPath[r][c]) {
          std::cout << "\033[32m" << "*" << "\033[0m"; // green star
        } else {
          std::cout << "*";
        }
      }
      std::cout << "\n";
    }




  }


}
