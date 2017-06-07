#include <iostream>
#include <fstream>

#include "life.h"

using namespace std;

string *grid;

int numRows;
int numCols;

/*
Function: populateWorld
 
Description:  This function reads input file for processing.
              The data is stored in dynamically allocated
              memory with incrementing size. Once all input
              file data is read, allocated memory is freed.
 
Receives: fileName (string)
Constants: none
Returns: none
*/
void populateWorld (string fileName) {
    const int SIZE_INCREMENT = 3;
    char line[80];
    numRows = 0;
    numCols = 0;
    
    ifstream fin;                               // file stream declared
    fin.open (fileName.data());    // attempt to open input file
    
    // testing for successful input file open
    if (!fin) {
        cout << "Failed to open input file" << endl
                 << "Program terminated";
        fin.close();
    }
    
    grid = new string[SIZE_INCREMENT];
    
    while (fin.getline(line, 80)) {
        grid[numRows] = line;
        numCols = grid[numRows].length();
        numRows++;
        
        // testing for resize of grid
        if (numRows % SIZE_INCREMENT == 0) {
            // pointer to temporary grid of bigger size
            string *tempgrid = new string[numRows + SIZE_INCREMENT];
            
            for (int i = 0; i < numRows; i++) {
                tempgrid[i] = grid[i];
            }
            
            // free the grid memory
            delete [] grid;
            
            grid = tempgrid;
        }
    }
}

/*
Function: showWorld
 
Description:  This function shows grid as if it were
              a 2-dimensional array of characters.
 
Receives: none
Constants: none
Returns: none
*/
void showWorld() {
    // shows the grid
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            // show one cell of the grid
            cout << grid[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

/*
Function: findNumNeighbors
 
Description:  This function checks how many live neighbors
              each cell has. The number of live neighbors is
              returned.
 
Receives: row (int), col (int)
Constants: none
Returns: neighbors (int)
*/
int findNumNeighbors (int row, int col) {
    int neighbors = 0;
    
    if ( row - 1 >= 0 && col - 1 >= 0 )
   {
      if ( grid[row - 1][col - 1] == '1' )
         neighbors++;
   }
 
   if ( row - 1 >= 0 )
   {
      if ( grid[row - 1][col] == '1' )
         neighbors++;
   }
 
   if ( row - 1 >= 0 && col + 1 < numCols )
   {
      if ( grid[row - 1][col + 1] == '1' )
         neighbors++;
   }
 
   if ( col - 1 >= 0 )
   {
      if ( grid[row][col - 1] == '1' )
         neighbors++;
   }
 
   if ( col + 1 < numCols )
   {
      if ( grid[row][col + 1] == '1' )
         neighbors++;
   }
 
   if ( row + 1 < numRows || col - 1 >= 0 )
   {
      if ( grid[row + 1][col - 1] == '1' )
         neighbors++;
   }
 
   if ( row + 1 < numRows )
   {
      if ( grid[row + 1][col] == '1' )
         neighbors++;
   }
 
   if ( row + 1 < numRows || col + 1 < numCols )
   {
      if ( grid[row + 1][col + 1] == '1' )
         neighbors++;
   }
    
    return neighbors;
}

/*
Function: applyRule
 
Description:  This function checks each cell and applies
              the Game of Life rules.
 
Receives: neighbors (int), row (int), col (int)
Constants: none
Returns: cell (char)
*/
char applyRule( int neighbors, int row, int col) {
    char cell;      // holds live or dead cell status
    
    //apply rules for live cells
   if ( grid[row][col] == '1' )
   {
      if ( neighbors >= 4 ) //cell dies of overcrowding
         cell = '0';
 
      if ( neighbors <=1 )  //cell dies of loneliness
         cell = '0';
 
      if ( neighbors == 3 || neighbors == 2 )  //cell is unchanged
         cell = '1';
   }
   //apply rules for dead cells
   else if ( grid[row][col] == '0' )
   {
      if ( neighbors == 3 )  //cell is born
         cell = '1';
 
      if ( neighbors < 3 || neighbors > 3 )  //cell is unchanged
         cell = '0';
   }
 
   return cell;
}

/*
Function: iterateGeneration
 
Description:  This function creates a new generation grid from
              the older grid.
 
Receives: none
Constants: none
Returns: none
*/
void iterateGeneration ()
{
   int neighbors;
 
   string *newgrid = new string[numRows+1];
 
   for ( int row = 0; row < numRows; row++ )
   {
      string temp = "";  //creates a storage place for the next line
 
      for ( int col = 0; col < numCols; col++ )
      {
         //calls function to check for neighbors
         neighbors = findNumNeighbors ( row, col );
 
         //calls function to apply rules and adds cell to temp
         temp += applyRule ( neighbors, row, col );
      }
 
      //assigns row of generated cells to new grid
      newgrid[row] = temp;
 
   }
   //free the grid memory
   delete [] grid;
 
   grid = newgrid;
}