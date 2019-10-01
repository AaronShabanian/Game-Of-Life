#include "Grid.h"
#include <iostream>
#include <fstream>
using namespace std;
Grid::Grid(){
  //constructor was called from either classic mirror or donut.cpp
  string answer;
  //determines whether to run randomGrid() or chooseFile() depending on what user wants to do
  cout<<"Would you like to read from a file? ";
  cin>>answer;
  if(answer=="no"||answer=="No"){
    randomGrid();
  }
  else{
    chooseFile();
  }

}
Grid::~Grid(){

}

void Grid::randomGrid(){
  double dec=0;
  double num=0;
  int width=0;
  int length=0;
  //gets dimensions of grid
  cout<<"Enter the width of the grid: ";
  cin>>width;
  cout<<"Enter the height of the grid: ";
  cin>>length;
  width1=width;
  length1=length;
  //gets concentration
  cout<<"Enter random decimal between 0 and 1: ";
  cin>>dec;
  //creates double pointer to the array with the given dimensions
  arr2 = new char*[length];
  for(int i=0; i<length; i++){
     arr2[i] = new char[width];
  }
  //puts either X or - in each element of the array depending on if the random number is greater than or
  //less than the concentration number given
  for(int i=0; i<length; i++){
    for(int j=0; j<width; j++){
      num=((double) rand() / (RAND_MAX));
      if(num<dec){
          arr2[i][j]='X';
      }
      else{
          arr2[i][j]='-';
      }
    }
  }

}

void Grid::chooseFile(){
  string answerFile="";
  int dec=0;
  int length=0;
  double num=0;
  int counter=0;
  string filename="";
  int width=0;

  string line;
  //gets name of file
    cout<<"Enter file name";
    cin>>filename;
    ifstream readfile (filename);
    //determines dimensions of array included in file
    if(readfile.is_open()){
    while(getline(readfile, line)){
      width=line.length();
      counter++;
     }
  length=counter;
}
else{
  cout<<"File doesn't exist. ";
}
//creates pointer to the array
 arr2= new char*[length];
for(int i=0; i<length; i++){
   arr2[i] = new char[width];
}

readfile.close();
//closes and re-opens the file to copy whats in the file to the array that has been created
ifstream readfile2 (filename);
if(readfile2.is_open()){
   int j=0;
while(getline(readfile2, line)){
  for(int i=0; i<width; i++){
    arr2[j][i]=line[i];
  }
  j++;
}
}
width1=width;
length1=length;
readfile2.close();
}
