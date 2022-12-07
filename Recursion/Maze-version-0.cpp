//********************************************************************
//  Maze.cpp       
//
//  Represents a maze of characters. The goal is to get from the
//  top left corner to the bottom right, following a path of 1s.
//********************************************************************
#include <iostream>

using namespace std;

// global constants
const int ROWS = 8;
const int COLS = 13;
const int WALL = 0;
const int OPEN = 1;
const int PATH = 3;


void printMaze(int grid[ROWS][COLS])
{
   for (int row=0; row < ROWS; row++)
   {
      for (int col=0; col < COLS; col++)
      {
         char out = '.';
         if (grid[row][col] == WALL)
            out = '+';
         if(grid[row][col] == PATH)
            out = '*';
         cout << out << " ";
      }
      cout << "\n";
   }
}

int main()
{
 
   int grid[ROWS][COLS] = {{1,1,1,0,1,1,0,0,0,1,1,1,1},
                           {1,0,1,1,1,0,1,1,1,1,0,0,1},
                           {0,0,0,0,1,0,1,0,1,0,1,0,0},
                           {1,1,1,0,1,1,1,0,1,0,1,1,1},
                           {1,0,1,0,0,0,0,1,1,1,0,0,0},
                           {1,0,1,1,1,1,1,1,0,1,0,1,0},
                           {1,0,0,0,0,0,0,0,0,0,1,1,1},
                           {1,1,1,1,1,1,1,1,1,1,1,0,1} };  
                           
   printMaze(grid);

}
