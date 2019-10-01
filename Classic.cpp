#include <unistd.h>
#include "Classic.h"
#include "Grid.h"
#include <iostream>
#include <fstream>
using namespace std;
Classic::Classic(){
}

Classic::~Classic(){

}
void Classic::classic(){
//asking what way they would like the program to be run by setting up booleans for each way and using them throughout
//the entire class
  bool write=false;
  bool pause=false;
  bool enter=false;
  ofstream myfile ("game.out");
  string enter1;
  int answer;
  cout<<"Enter the number of your selection:"<<"\n"<< "(1)Press enter between generations."<<"\n"<< "(2)Pause between generations"<<"\n"<< "(3)Write to a seperate file ";
  cin>>answer;
  if(answer==2){
    pause=true;
  }
  else if(answer==1){
    enter=true;
  }
  else if(answer==3){
    write=true;
  }
  else{
    cout<<"Invalid input";
  }
  //Calls the grid class which then calls the grid function in the grid constructor
  Grid grid;
    char one;
    char two;
    int length = grid.length1;
    int width = grid.width1;
    bool equals=true;
    char ** arr=grid.arr2;
    //creating a new 2d pointer to an array with the same size as the one created by Grid.grid()
    nextArr= new char*[length];
    for(int i=0; i<length; i++){
       nextArr[i] = new char[width];
    }
    //prints original array
    for(int i=0; i<length; i++){
      for(int j=0; j<width; j++){
        if(enter==true||pause==true){
          cout<<arr[i][j];
        }
        else{
          myfile<<arr[i][j];
        }
      }
      if(write==true){
      myfile<<"\n";
      }
      else{
      cout<<"\n";
    }
    }
    int counter=1;
    int neighbors=0;
    while(true){
      //function outputs in different ways depending on what the user wanted
      if(enter==true){
        cin.ignore();
      }
      else if(pause==true){
        sleep(1);
      }
    int similarity=0;
    //Checks to see if the new array is the same as the previous generation and determines whether to end the program
    if(counter>1){
      for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
          if(arr[i][j]!=nextArr[i][j]){
            similarity++;
          }
          arr[i][j]=nextArr[i][j];
        }
      }
      if(similarity==0){
        cout<<"Life has stabilized"<<endl;
        break;
      }
    }
    if(write==true){
      if (myfile.is_open())
      {
      myfile<<"\n";
      myfile<<counter;
      myfile<<"\n";
    }
    }
    else{
    cout<<"\n";
    cout<<counter;
    cout<<"\n";
  }
    //Checks neighbors by following the classic rules
      for (int i=0; i<length;i++){
        for(int j=0; j<width;j++){
          neighbors=0;
          if(i==0&&j==0){
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i+1][j+1]=='X'){
              neighbors++;
            }
            if(arr[i][j+1]=='X'){
              neighbors++;
            }
          }
          else if(i==0&&j==width-1){
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i+1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i][j-1]=='X'){
              neighbors++;
            }
          }
          else if(i==length-1&&width==0){
            if(arr[i-1][j]=='X'){
              neighbors++;
            }
            if(arr[i-1][j+1]=='X'){
              neighbors++;
            }
            if(arr[i][j+1]=='X'){
              neighbors++;
            }
          }
          else if(i==length-1&&j==width-1){
            if(arr[i-1][j]=='X'){
              neighbors++;
            }
            if(arr[i-1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i][j-1]=='X'){
              neighbors++;
            }
          }
          else if(i==0){
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i][j+1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j+1]=='X'){
              neighbors++;
            }
            if(arr[i][j-1]=='X'){
              neighbors++;
            }
          }
            else if(i==length-1){
              if(arr[i-1][j]=='X'){
                neighbors++;
              }
              if(arr[i][j+1]=='X'){
                neighbors++;
              }
              if(arr[i-1][j-1]=='X'){
                neighbors++;
              }
              if(arr[i-1][j+1]=='X'){
                neighbors++;
              }
              if(arr[i][j-1]=='X'){
                neighbors++;
              }
          }
          else if(j==0){
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i][j+1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j+1]=='X'){
              neighbors++;
            }
            if(arr[i-1][j]=='X'){
              neighbors++;
            }
            if(arr[i-1][j+1]=='X'){
              neighbors++;
            }
          }
          else if(j==width-1){
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i][j-1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i-1][j]=='X'){
              neighbors++;
            }
            if(arr[i-1][j-1]=='X'){
              neighbors++;
            }
          }
          else{
            if(arr[i+1][j]=='X'){
              neighbors++;
            }
            if(arr[i][j-1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i-1][j]=='X'){
              neighbors++;
            }
            if(arr[i-1][j-1]=='X'){
              neighbors++;
            }
            if(arr[i-1][j+1]=='X'){
              neighbors++;
            }
            if(arr[i][j+1]=='X'){
              neighbors++;
            }
            if(arr[i+1][j+1]=='X'){
              neighbors++;
            }
          }
          if(neighbors==0||neighbors==1){
            nextArr[i][j]='-';
          }

          else if(neighbors==2){
            nextArr[i][j]=arr[i][j];
          }
          else if(neighbors==3){
            nextArr[i][j]='X';
          }
          else if(neighbors>3){
            nextArr[i][j]='-';
          }
          if(write==true){
            if (myfile.is_open())
            {
            myfile<<nextArr[i][j];
          }
          }
          else{
          cout<<nextArr[i][j];
        }
          one=nextArr[i][j];
          two=arr[i][j];

        }
        if(write==true){
          if (myfile.is_open())
          {
          myfile<<"\n";
          }
        }
        else{
        cout<<"\n";
      }
      }
      //generation has been created will start again
      counter++;
      if(nextArr==arr){
        counter=100;
      }


    }
    if(write==true){
      cout<<"Your file has been written to game.out. "<<"\n";
    }
    myfile.close();
  }
