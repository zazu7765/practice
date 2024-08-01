#include <cmath>
#include <iostream>
// impact factor = total citations by articles published / total number of
// articles published round upwards
int articles, required_impact;
double minimum_impact;
int main() {
  std::cin >> articles >> required_impact;
  minimum_impact = required_impact - 0.99;
  std::cout << std::ceil(minimum_impact * articles) << "\n";
}
