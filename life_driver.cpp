//This file is a driver program for the life.cpp module

#ifdef linux
#define LINUX false
#define WINDOWS true
#endif

#ifdef __WIN32__
#define LINUX false
#define WINDOWS true
#endif


#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <windows.h> // includes the Sleep function for Windows

#include "life.h"

const string FILE_NAME = "starting_grid.txt";

using namespace std;

const int NUM_GENERATIONS = 300;    // set to a smaller number for debugging

int main(int argc, char** argv) {

    populateWorld (FILE_NAME);
    showWorld();
    
    for (int iteration = 0; iteration < NUM_GENERATIONS; iteration++) {
        cout << "\033[2J\033[1;1H";     // clears screen for linux
        
        iterateGeneration();
        showWorld();
        //Sleep(1500);  // use to see the changes at a slower rate for Windows
    }
    
    return 0;
}

