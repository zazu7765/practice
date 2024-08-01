//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;
// <string> variables
int main() {
  string name = "Daniel";
  char initial = 'I';

// numbers
  short shortAge = 10; //minimum 16-bits signed
  int intAge = 20;     //minimum 16-bits signed, > than short
  long longAge = 30;   //minimum 32-bits signed
  long long longlongAge = 40; //minimum 64-bits signed

  float myGPA = 2.5f; //single-precision floating point
  double yourGPA = 3.5; //double-precision floating point
  long double theirGPA = 3.14; //extended-precision floating point

  bool isTall = true;
  cout << "Your name: "<<name<<endl;
  cout << "Your initial: "<< initial << endl;
  cout << "Your age: "<< longlongAge << endl;
  cout << "Your gpa: " << myGPA << endl;
  cout << "Tall boolean: " << isTall << endl;
  return 0;
}