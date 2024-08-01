#include <iostream>
int G, T, N, weight, remaining, actualRemaining, item;
int main() {
  using namespace std;
  cin >> G >> T >> N;
  remaining = G - T;
  actualRemaining = remaining * 0.9;
  weight = 0;
  for (size_t i = 0; i < N; i++) {
    cin >> item;
    weight += item;
  }
  cout << actualRemaining - weight << endl;
}
