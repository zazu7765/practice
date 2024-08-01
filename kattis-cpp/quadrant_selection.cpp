#include <iostream>
int main() {
  int p1, p2;
  std::cin >> p1 >> p2;
  if (p1 > 0 && p2 > 0)
    std::cout << 1 << "\n";
  else if (p1 > 0 && p2 < 0)
    std::cout << 4 << "\n";
  else if (p1 < 0 && p2 > 0)
    std::cout << 2 << "\n";
  else
    std::cout << 3 << "\n";
}
