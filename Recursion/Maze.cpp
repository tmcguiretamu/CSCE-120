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
const int TRIED = 2;
const int PATH = 3;

static bool done = false;

//-----------------------------------------------------------------
//  Determines if a specific location is valid.
//-----------------------------------------------------------------
bool valid(int grid[ROWS][COLS], int row, int column)
{
   bool result = false;
 
   // check if cell is in the bounds of the matrix
   if (row >= 0 && row < ROWS &&
          column >= 0 && column < COLS)

      //  check if cell is not blocked and not previously tried
      if (grid[row][column] == OPEN)
         result = true;

   return result;
}

//-----------------------------------------------------------------
//  Attempts to recursively traverse the maze. Inserts special
//  characters indicating locations that have been tried and that
//  eventually become part of the solution.
//-----------------------------------------------------------------
void traverse(int grid[ROWS][COLS], int row, int column)
{
   done = false;

   if (valid(grid, row, column))
   {
      grid[row][column] = TRIED;  // this cell has been tried

      if (row == ROWS-1 && column == COLS-1)
         done = true;  // the maze is solved
      else
      {
         traverse(grid, row+1, column);     // down
         if (!done)
            traverse(grid, row, column+1);  // right
         if (!done)
            traverse(grid, row-1, column);  // up
         if (!done)
            traverse(grid, row, column-1);  // left
      }

      if (done)  // this location is part of the final path
         grid[row][column] = PATH;
   }
      
}

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

   traverse(grid, 0, 0);
   if (done)
      cout << "The maze was successfully traversed!\n";
   else
      cout << "There is no possible path.";

   printMaze(grid);
   



}
