//
// Created by zsazu on 2022-02-01.
//
#include <iostream>
#include "profile.hpp"
using namespace std;
int main(){
  Profile sam("Sam Drakilla",30, "New York", "USA", "he/him");
  sam.addHobby("Piano");
  sam.addHobby("Gaming");
  cout<<sam.viewProfile();
  return 0;
}
