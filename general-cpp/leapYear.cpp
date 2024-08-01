//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;

int main(){
  int year;
  cout<<"Enter a year (between 1000 and 9999): ";
  cin>>year;
  if(year<1000 || year > 9999){
    cout<<"Invalid year..."<<endl;
  }
  else if(year%4 == 0 && year%100 == 0 || year%400 == 0){
    cout<<year<<" is a leap year!"<<endl;
  }
  else{
    cout<<year<<" is not a leap year!"<<endl;
  }
  return 0;
}