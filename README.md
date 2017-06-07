# C++ Game Of Life
This is an implementation of the Game of Life using C++ language.

# Usage
Just make sure the starting_grid.txt file is located in the same directory as the life.cpp, life.h, and life_driver.cpp files so the program can import the grid.

# Rules
For those that are not familiar with the Game of Life, here are the rules: 
1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

In this project, a live cell is represented by a '1' and a dead cell is represented by a '0'.


More on the Game Of Life here https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life 
