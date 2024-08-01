#include <iostream>
using us = unsigned short;
us code;
int main() {
  std::cin >> code;
  us second = code % 10;
  code = code / 10;
  us first = code % 10;
  std::cout << second << first << "\n";
}
