// This program computes the number of moves
// in a solution to the Towers of Hanoi puzzle.
#include <iostream>
using namespace std;

static unsigned int num_moves = 0;

// Function prototype
void moveDiscs(int, char, char, char);

int main()
{
 
   const char FROM_PEG = 'A';    // Initial "from" peg
   const char TO_PEG = 'C';      // Initial "to" peg
   const char TEMP_PEG = 'B';    // Initial "temp" peg
   unsigned num_discs;                // Number of discs to move
   
   cout << "Please enter the maximum number of discs -> ";
   cin >> num_discs;
   // Solve the puzzle.
 
   for (unsigned i = 0; i <= num_discs; i++)  {
      num_moves = 0;
      moveDiscs(i, FROM_PEG, TO_PEG, TEMP_PEG);
      cout << i << " discs:  total number of moves= " << num_moves << endl;
   }
   return 0;
}

//***************************************************
// The moveDiscs function displays a disc move in   *
// the Towers of Hanoi game.                        *
// The parameters are:                              *
//    num:     The number of discs to move.         *
//    fromPeg: The peg to move from.                *
//    toPeg:   The peg to move to.                  *
//    tempPeg: The temporary peg.                   *
//***************************************************

void moveDiscs(int num, char fromPeg, char toPeg, char tempPeg)
{
   // using a static variable to keep track of total moves 
   // over all calls to the function 
   
   if (num > 0)  // moves are only required if there is at least one disc 
   {
      moveDiscs(num - 1, fromPeg, tempPeg, toPeg);
/*      cout << "Move a disc from peg " << fromPeg
           << " to peg " << toPeg << endl; */
      ++num_moves;
      moveDiscs(num - 1, tempPeg, toPeg, fromPeg);
   }
}