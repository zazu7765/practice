//
// Created by zsazu on 2022-02-07.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn = 1e5;
int n;
int m;
int arr[mn];

// function to calculate people per time (seconds)
ll peoplePerTime(ll time) {
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += time / (ll) arr[i];
  }
  return res;
}
int main(){
  istream::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  //binary search
  ll l = 1;
  ll r = 1e18; //worst case scenario: 1e9 (people) and 1 desk that takes 1e9 (time) seconds
  while (l < r) {
    //mid point of search
    long long mid = (l+r)/2;
    // if too many set r to mid
    if (peoplePerTime(mid) >= m) {
      r = mid;
      // if too little set r to mid+1;
    } else {
      l = mid+1;
    }
    // prints when l < r (loop breaks)
  }cout<<l;
return 0;
}

