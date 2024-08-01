//
// Created by zsazu on 2022-02-02.
//
#include <iostream>
#include <string>
#include "functions.hpp"
using namespace std;
int main() {
  string word = "banana";
  string text = "i love bananas, potatoes, and brocolli. i also love banana bread and apple pie, not banana pie";
  bleeper(word, text);
  for (int letter = 0; letter < text.size(); letter++){
    cout<< text[letter];
  }
}