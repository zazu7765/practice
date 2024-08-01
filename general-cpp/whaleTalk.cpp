//
// Created by zsazu on 2022-01-30.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  string toTranslate = "banana cream pie";
  vector<char> vowels;
  vowels.push_back('a');
  vowels.push_back('e');
  vowels.push_back('i');
  vowels.push_back('o');
  vowels.push_back('u');

  vector<char> translation;
  for(int i = 0; i < toTranslate.size(); i++){
    for(int j = 0; j < vowels.size(); j++){
      if(toTranslate[i] == vowels[j]){
        translation.push_back(toTranslate[i]);
      }
      if(toTranslate[i] == 'e' || toTranslate[i] == 'u'){
        translation.push_back(toTranslate[i]);
      }
    }
  }
  for(int k = 0; k < translation.size(); k++){
    cout<< translation[k];
  }
  cout<<endl;
}