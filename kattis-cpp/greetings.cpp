#include <algorithm>
#include <iostream>
#include <string>
std::string input;
int main() {
  std::cin >> input;
  if (input.substr(0, 2) == "he" &&
      input.substr(input.length() - 2, input.length()) == "ey") {
    std::string newstr = "h";
    size_t count = std::count(input.begin(), input.end(), 'e');
    std::string thees(count * 2, 'e');
    newstr.append(thees);
    newstr.append("y");
    std::cout << newstr << std::endl;
  }
}
