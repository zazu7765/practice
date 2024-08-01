#include <algorithm>
#include <iostream>
#include <string>
int A, B;
std::string str_a, str_b;
int main() {
  std::cin >> A >> B;
  str_a = std::to_string(A);
  str_b = std::to_string(B);
  std::reverse(str_a.begin(), str_a.end());
  std::reverse(str_b.begin(), str_b.end());
  A = stoi(str_a);
  B = stoi(str_b);
  std::cout << std::max(A, B) << "\n";
}
