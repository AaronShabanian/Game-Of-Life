#ifndef GRID_H
//ifndef was used to define a token to stop me from getting errors
#define GRID_H

#include <iostream>
using namespace std;
class Grid{
public:
  Grid();
  ~Grid();
  void randomGrid();
  //Function to create grid if user wants to create a random one
  void chooseFile();
  //Function to create grid is user wants to read from a file
  int width1;
  //stores width and length to be used in different classes
  int length1;
  char ** arr2 = NULL;
  //stores pointer to an array to be used in later classes

};

#endif /*GRID_H*/
