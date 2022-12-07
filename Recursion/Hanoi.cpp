// This program displays a solution to the Towers of Hanoi puzzle.
#include <iostream>
using namespace std;

// Function prototype
void moveDiscs(int, char, char, char);

static int nmoves = 0;

int main()
{
   const char FROM_PEG = 'A';    // Initial "from" peg
   const char TO_PEG = 'C';      // Initial "to" peg
   const char TEMP_PEG = 'B';    // Initial "temp" peg
   int num_discs;                // Number of discs to move
   
   cout << "Please enter the number of discs -> ";
   cin >> num_discs;
   // Solve the puzzle.
   moveDiscs(num_discs, FROM_PEG, TO_PEG, TEMP_PEG);
   cout << "All the pegs are moved!\n";
   cout << "It took " << nmoves << "moves\n";
   
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
   if (num > 0)
   {

      moveDiscs(num - 1, fromPeg, tempPeg, toPeg);
      cout << "Move a disc from peg " << fromPeg
           << " to peg " << toPeg << endl;
      ++nmoves;     
      moveDiscs(num - 1, tempPeg, toPeg, fromPeg);
   }
}