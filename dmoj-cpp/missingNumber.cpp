//
// Created by zsazu on 2022-02-04.
// CSES Problem Set: Missing Number
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  long long numToSum;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n-1; i++){
    cin >> numToSum;
    sum += numToSum;
  }
  long long endValue = (n*(n+1))/2-sum;
  // sum formula ^^
  cout << endValue << endl;
  return 0;
}

