#include <iostream>
int N;
int main() {
  std::cin >> N;
  if (N & 1)
    std::cout << "first"
              << "\n";
  else
    std::cout << "second"
              << "\n";
}
