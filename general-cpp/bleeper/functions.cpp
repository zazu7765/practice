//
// Created by zsazu on 2022-02-02.
//
#include <string>
using namespace std;
void censor(string word, string &text, int i){
  // pass in the word, bleep out the word by replacing each character
  for(int c = 0; c < word.size(); c++){
    //replace all the text word with asterisks per character
    text[i+c] = '*';
  }
}

void bleeper(string word, string &text){
  for (int i = 0; i < text.size(); i++){
    int matchWord = 0;

    for(int j=0; j < word.size(); j++){
      if(text[i+j] == word[j]){
        matchWord++;
      }
    }
    if(matchWord == word.size()){
      censor(word, text, i);
    }
  }
}