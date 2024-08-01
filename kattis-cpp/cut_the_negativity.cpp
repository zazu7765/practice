#include <iostream>
#include <sstream>
#include <vector>
int N;
int val;
int numFlights = 0;
std::stringstream ss;
int main() {
  using namespace std;
  vector<vector<int> > flights;
  vector<string> directFlights;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    vector<int> row;
    for (size_t j = 0; j < N; j++) {
      cin >> val;
      row.push_back(val);
    }
    flights.push_back(row);
  }
  for (size_t i = 0; i < flights.size(); i++) {
    int city1 = i + 1;
    for (size_t j = 0; j < flights[i].size(); j++) {
      if (flights[i][j] != -1) {
        int city2 = j + 1;
        numFlights++;
        ss << city1 << " " << city2 << " " << flights[i][j] << "\n";
      }
    }
  }
  cout << numFlights << "\n";
  cout << ss.str();
}
