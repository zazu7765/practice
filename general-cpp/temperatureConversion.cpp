//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;
int main(){
  double tempf;
  double tempc;
  cout<<"Enter the temperature in Fahrenheit: ";
  cin >> tempf;
  tempc = (tempf-32)/1.8;
  cout<<"The temperature in celsius is " << tempc << " degrees Celsius..." <<endl;
  return 0;
}

