#include <iostream>
using namespace std;
class GameOfLife{
public:
  GameOfLife();
  ~GameOfLife();
  int *randomGrid();
  int width=0;
  int length=0;
  int *chooseFile();
  void classic();
};
