//
// Created by zsazu on 2022-02-09.
//
#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  // input number
  cin>>n;
  // height / width collection
  // height has n+1 since we're getting n+1 values (n that match, 1 more for the last edge)
  vector<int> heights(n+1);
  vector<int> widths(n);
  // initialize area (start at 0)
  double totalArea = 0.0;
  // input heights
  for(int i =0; i <= n; i++){
    cin>>heights[i];
  }
  // input widths
  for(int i = 0; i < n; i++){
    cin>>widths[i];
  }
  //actual codey part
  for(int i = 0; i < n; i++){
    double area = widths[i] * (heights[i]+heights[i+1]);
    //thank you editorial for the tip
    totalArea+=area;
  }
  cout<<fixed<<totalArea/2.0<<"\n";
}