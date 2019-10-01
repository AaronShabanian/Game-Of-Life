#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
  string mode;
  cout<<"What mode would you like to play, classic, donut or mirror? "<<endl;
  cin>>mode;
  if(mode=="classic"){
    Classic classic;
    //within the classic class, the grid class is called so by declaring the classic class, we are declaring the grid class
    classic.classic();
    //calls the classic function within the classic class which is explained in the classic.h file
  }
  else if(mode=="donut"){
    Donut donut;
    //within the donut class, the grid class is called so by declaring the donut class, we are declaring the grid class
    donut.donut();
    //calls the donut function which is explained in the donut.h file
  }
  else if(mode=="mirror"){
    Mirror mirror;
    //within the mirror class, the grid class is called so by declaring the mirror class, we are declaring the grid class
    mirror.mirror();
    //calls the mirror function which is explained in the mirror.h file
  }
  else{
    cout<<"You did not enter a valid game mode. "<<endl;
    //Gives message if user does not enter valid mode
  }

return 0;
}
