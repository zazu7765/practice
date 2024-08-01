//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;
int main(){
  float miles;
  float kilometers;
  cout << "Enter the distance in miles: " << endl;
  cin >> miles;
  float conversionValue = 1.609344;
  kilometers = miles * conversionValue;
  cout << "The distance is " << kilometers << " kilometers" << endl;
  return 0;
}