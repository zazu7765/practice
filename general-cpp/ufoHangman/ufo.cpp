//
// Created by zsazu on 2022-01-31.
//
#include <iostream>
#include "ufoFunctions.hpp"
using namespace std;
int main(){
  greetUser();
  string codeword = "banana";
  string answer = "______";
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;
  while(answer != codeword && misses<7){
    cout<<"Please enter your guess: ";
    cin>>letter;
    for(int i =0; i<codeword.size();i++){
      if(letter == codeword[i]){
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess){
      cout<<"You got a letter!";
    }
    else{
      cout<<"You got a wrong guess! The aliens bring your friend closer...";
      incorrect.push_back(letter);
      misses++;
    }
    showMisses(misses);
    showStatus(incorrect, answer);
    guess = false;
  }
  endGame(answer,codeword);
  return 0;
}
