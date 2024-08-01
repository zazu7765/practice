//
// Created by zsazu on 2022-02-13.
//
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int N;
vector<vector<int>> arr;
ll score(ll p){
  ll output = 0;
  for(auto & i : arr){
    //get length of walk
    ll walkLength = abs(p-i[0])-i[2];
    if(walkLength>0){
      output+= walkLength * i[1];
    }
  }
  return output;
}
int main(){
  cin>>N;
  arr.resize(N, vector(3,0));
  ll bottom = INT_MAX;
  ll top = 0;
  for(int i = 0; i < N; i++){
    // place inputs p/w/d in 2d array
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    //set top to p if p bigger
    if(arr[i][0]>top){
      top = arr[i][0];
    }
    //set bottom to p if p smaller
    if(arr[i][0]<bottom){
      bottom = arr[i][0];
    }
  }
  //midpoint for binary search
  ll centre = 0;
  //value of the score for the midpoint
  ll s = 0;
  //binary search to find the 'best score'
  while(bottom<=top){
    centre = (bottom+top)/2;
    // grab midpoint value
    s = score(centre);
    // grab left of midpoint
    ll sLeft = score(centre-1);
    // grab right of midpoint
    ll sRight = score(centre+1);
    // if smaller then both then something is hella wrong
    if(s<sRight && s<sLeft){
      break;
    }
    // if equal then you're at the bottom already
    if(s == sRight || s == sLeft){
      break;
    }
    //recalibrate the top
    if(s < sRight){
      top = centre-1;
    }
    //recalibrate the bottom
    else if (s < sLeft){
      bottom = centre+1;
    }
  }
  //output best score
  cout<<s;
  return 0;
}