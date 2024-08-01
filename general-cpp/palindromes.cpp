//
// Created by zsazu on 2022-01-31.
//
#include <iostream>
#include <algorithm> //reverse function
using namespace std;

bool checkPalidrome(string text){
  string reversed = text;
  reverse(reversed.begin(),reversed.end());
  if(reversed == text){
    return true;
  }
  else{}
  return false;
}

int main(){
  cout<< checkPalidrome("2002")<< endl;
  cout<< checkPalidrome("civic")<< endl;
  cout<< checkPalidrome("tenet")<< endl;
  cout<< checkPalidrome("banana")<< endl;
}