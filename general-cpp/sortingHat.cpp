//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;

int main(){
  // initial yes/no q
  char yn;
  // house point declarations
  int g = 0;
  int h = 0;
  int r = 0;
  int s = 0;
  int a1,a2,a3,a4;
  cout<<"---------------\n";
  cout<<"The Sorting Hat\n";
  cout<<"---------------\n\n";
  // yes/no entrance dialogue
  cout<<"Are you willing to take the test? (y/n): ";
  cin>>yn;
  if(yn == 'n'){
    return 0;
  // actual quiz start:
  }else{
    // not gonna clear console because system() is evil i guess
    // question 1 dialogue
    cout<<"Question 1: When I die, I want people to remember me as: \n\n"<<"1: The Good\n"<<"2: The Great\n"<<"3: The Wise\n"<<"4: The Bold\n\n"<<endl;
    cout<<"Enter your answer: ";
    cin>> a1;
    switch(a1){
      case 1:
        h++;
        break;
      case 2:
        s++;
        break;
      case 3:
        r++;
        break;
      case 4:
        g++;
        break;
    }
    // question 2 dialogue
    cout<<"\nQuestion 2: I prefer: "<<"\n1: Dusk\n"<<"2: Dawn\n"<<endl;
    cout<<"Enter your answer: ";
    cin>> a2;
    switch(a2){
      case 1:
        g++;
        r++;
        break;
      case 2:
        h++;
        s++;
        break;
    }
    //question 3 dialogue
    cout<<"\nQuestion 3: Which instrument's sound is most pleasing? \n\n"<<"1: Violin\n"<<"2: Trumpet\n"<<"3: Piano\n"<<"4: Drum\n"<<endl;
    cout<<"Enter your answer: ";
    cin>> a3;
    switch(a3){
      case 1:
        s++;
        break;
      case 2:
        h++;
        break;
      case 3:
        r++;
        break;
      case 4:
        g++;
        break;
    }
    //question 4 dialogue
    cout<<"\nQuestion 4: Which path tempts you the most? \n\n"<<"1: Wide, sunny lane\n"<<"2: Dark, narrow alley\n"<<"3: Twisting, leafy path through the woods\n"<<"4: Cobbled, mysterious street\n"<<endl;
    cout<<"Enter your answer: ";
    cin>> a4;
    switch (a4){
      case 1:
        h++;
        break;
      case 2:
        s++;
        break;
      case 3:
        g++;
        break;
      case 4:
        r++;
        break;
    }
    //final dialogue
    int max = 0;
    string selection;
    if(g>max){
      max = g;
      selection = "Gryffindor";
    }
    if(s>max){
      max = s;
      selection = "Slytherin";
    }
    if(h>max){
      max = h;
      selection = "Hufflepuff";
    }
    if(r>max){
      max = r;
      selection = "Ravenclaw";
    }
    cout<<"\n\nCongratulations on finishing the test, you have been sorted into: "<< selection << "!\n";
  }
  return 0;
}