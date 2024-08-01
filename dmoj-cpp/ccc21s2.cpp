//
// Created by zsazu on 2022-02-12.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
  //row
  int M;
  //column
  int N;
  //instructions
  int K;
  cin >> M >> N >> K;
  //2d kinda?
  vector<int> row(M, 0);
  vector<int> column(N, 0);
  //iterate for instructions
  for (int i = 0; i < K; i++) {
    char choice;
    int position;
    cin >> choice >> position;
    //use position-1 because index starts at 0 but grid works with 1
    if (choice == 'R') {
      row[position-1]++;
    } else {
      column[position-1]++;
    }
  }
  int count = 0;
  for(int m = 0; m < M; m++){
    for(int n = 0; n < N; n++){
      if((row[m]+column[n])%2 == 1){
        count++;
      }
    }
  }
  cout<<count;
  return 0;
}