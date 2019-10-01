#include <iostream>
#include "Grid.h"
using namespace std;
class Mirror{
public:
  Mirror();
    //Grid function is called from the constructor allowing either a random Grid to be created or a one to be created from a file.
  ~Mirror();
  void mirror();
  /* essentially the same as the classic function with the only difference being the way the neighbors section
  is calculated */
  char ** nextArr=NULL;
};
