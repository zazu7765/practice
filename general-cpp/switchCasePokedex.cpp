//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  srand((int)time(0));
  int number = (rand()%10)+1;
  switch(number){
    case 1:
      cout<<"Bulbasaur\n";
      break;
    case 2:
      cout<<"Ivysaur\n";
      break;
    case 3:
      cout<<"Venosaur\n";
      break;
    case 4:
      cout<<"Charmander\n";
      break;
    case 5:
      cout<<"Charmeleon\n";
      break;
    case 6:
      cout<<"Charizard\n";
      break;
    case 7:
      cout<<"Squirtle\n";
      break;
    case 8:
      cout<<"Wartortle\n";
      break;
    case 9:
      cout<<"Blastoise\n";
      break;
    default:
      cout<<"Unknown\n";
      break;
  }
  return 0;
}
