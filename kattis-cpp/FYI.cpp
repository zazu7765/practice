#include <iostream>
#include <string>
long long n;
int main() {
  std::cin >> n;
  if (std::stoi(std::to_string(n).substr(0, 3)) == 555) {
    std::cout << 1 << std::endl;
    return 0;
  }
  std::cout << 0 << std::endl;
}
