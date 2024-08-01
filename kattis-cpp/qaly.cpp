#include <array>
#include <iostream>
size_t N;
double totalqaly;
int main() {
  totalqaly = 0.0;
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    double temp1;
    double temp2;
    std::cin >> temp1;
    std::cin >> temp2;
    totalqaly += (temp1 * temp2);
  }
  std::cout << totalqaly << std::endl;
}
