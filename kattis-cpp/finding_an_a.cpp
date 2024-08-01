#include <algorithm>
#include <iostream>
#include <string>
std::string tofind;
int main() {
  std::cin >> tofind;
  int a_index = tofind.find('a');
  std::cout << tofind.substr(a_index) << std::endl;
}
