//
// Created by zsazu on 2022-02-08.
//
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  //speedy i/o please
  istream::sync_with_stdio(false);
  cin.tie(nullptr);

  ll testCases;
  cin>>testCases;
  for(int i=0; i< testCases; i++){
    ll nPositiveIntegers;
    ll sNumberSumMissing;
    cin >> nPositiveIntegers >> sNumberSumMissing;
    ll correctSum = nPositiveIntegers*(nPositiveIntegers+1)/2; //sum formula
    double difference = correctSum - sNumberSumMissing;
    // start creating pairs from the middle of the difference of sum (all that can add up to the missing sum)
    ll pairOne;
    ll pairTwo;
    // use 2.0 since difference is a double so you don't want to mess up conversions
    ll spitOut = ceil(difference/2.0)-1; // default output
    pairOne = ceil(difference/2.0)-1; // first number to check ( we want to round up)
    pairTwo = floor(difference/2.0)+1; // second number to check ( we want to round down)
    // make sure they pair up together as a sum
    if (pairOne > nPositiveIntegers - pairTwo){
      // if bigger then remove all that jazz from the spitout
      spitOut -= pairOne - (nPositiveIntegers - pairTwo + 1);
    }
    cout<<spitOut<<"\n"; //no endl for speeeeeeed
  }
}