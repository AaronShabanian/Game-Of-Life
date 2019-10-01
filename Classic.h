#include <iostream>
#include "Grid.h"
using namespace std;
class Classic{
public:
  Classic();
  //Grid function is called from the constructor allowing either a random Grid to be created or a one to be created from a file.
  ~Classic();
  void classic();
  /*calls the classic function if the user decides to play the classic game mode.
  reads through the grid created in the grid class from either the randomGrid function
  or chooseFile function depending on whether the person wanted to read from a file or
  create a randomGrid. Then asks user whether they want pauses, press enter or for it
  to be outputted to a file. Compares neighbors based on the rules of classic mode and
  decides what the resulting grid should be. Keeps repeating the process until 2 generations
  are the same
  */
  char ** nextArr = NULL;
};
