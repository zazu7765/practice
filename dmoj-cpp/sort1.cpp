//
// Created by zsazu on 2022-02-09.
//
#include <bits/stdc++.h>
using namespace std;
void swapArr(int *one, int *two){
  int temp = *one;
  *one = *two;
  *two = temp;
}
int main(){
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i=0; i < N; i++){
    cin>>arr[i];
  }
  for(auto h: arr){
    cout<< h<<" ";
  }
  cout<<"\n";
  for(int i = 0; i < N-1; i++){
    for(int j = 0; j < N-1; j++){
      if(arr[j] > arr[j+1]){
        swapArr(&arr[j],&arr[j+1]);
        for(auto k: arr){
          cout<<k<< " ";
        }
        cout<<"\n";
      }
    }
  }

  return 0;
}