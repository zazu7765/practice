//
// Created by zsazu on 2022-02-04.
// CSES Problem Set: Weird Algorithm
// modified for '3n+1' and 'Hailstone Numbers' on dmoj
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>> n;
  //cout<<n<<" ";
  int count = 0;
  while(n>1){
    if(n%2==0){
      n=n/2;
      count++;
    }
    else {
      n = (n * 3) + 1;
      count++;
    }
    //cout<<n<<" ";
  }
  cout<<count;
  return 0;
}