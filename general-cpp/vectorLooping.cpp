//
// Created by zsazu on 2022-01-30.
//
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int sumEven = 0;
  int prodOdd = 1;

  vector<int> numbers = {2, 4, 3, 6, 1, 9};
  for (int i = 0; i < numbers.size(); i++) {
    if(numbers[i]%2==0){
      sumEven = sumEven + numbers[i];
    }
    else{
      prodOdd = prodOdd * numbers[i];
    }
  }
  cout<<"even sums: "<<sumEven<<endl;
  cout<<"odd prods: "<<prodOdd<<endl;
  return 0;
}
