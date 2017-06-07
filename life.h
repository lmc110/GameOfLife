/**************************************************** 
This program reads an input file and adds the data
to a dynamically allocated grid. The grid consists of
live and dead cells. Once grid is populated with cells,
it is displayed to the screen. Each cell is then checked
for live neighbors and the rules are applied to it.
The next generation of cells are added to a new grid
and displayed to the screen.
*****************************************************/

#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void populateWorld (string fileName);
void showWorld();
void iterateGeneration();



#endif /* LIFE_H */

