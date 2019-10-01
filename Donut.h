#include <iostream>
#include "Grid.h"
using namespace std;
class Donut{
public:
  Donut();
  //Grid function is called from the constructor allowing either a random Grid to be created or a one to be created from a file.
  ~Donut();
  void donut();
  /* essentially the same as the classic function with the only difference being the way the neighbors section
  is calculated */
  char ** nextArr = NULL;
};
