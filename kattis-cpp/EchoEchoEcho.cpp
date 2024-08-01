#include <iostream>
#include <string>
std::string word;
std::string tripleword;
int main() {
  std::cin >> word;
  word.append(" ");
  tripleword.append(word);
  tripleword.append(word);
  tripleword.append(word);
  std::cout << tripleword << "\n";
}
