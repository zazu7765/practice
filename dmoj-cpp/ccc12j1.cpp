//
// Created by zsazu on 2022-02-08.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  istream::sync_with_stdio(false);
  cin.tie(nullptr);
  ll limit;
  ll speed;
  cin>>limit>>speed;
  string msg1 = "Congratulations, you are within the speed limit!";
  string msg2 = "You are speeding and your fine is $";
  int fine;
  ll difference = speed - limit;
  if(difference > 0 && difference < 21){
    fine = 100;
    cout<<msg2<<fine<<".";
  }
  else if (difference > 20 && difference < 31){
    fine = 270;
    cout<<msg2<<fine<<".";
  }
  else if (difference >= 31){
    fine = 500;
    cout<<msg2<<fine<<".";
  }
  else{
    cout<<msg1;
  }
  return 0;
}