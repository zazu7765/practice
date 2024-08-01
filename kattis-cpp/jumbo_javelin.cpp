#include <iostream>
short N;
int javelin, length;
int main() {
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    std::cin >> length;
    javelin += length;
    if (i != 0)
      javelin--;
  }
  std::cout << javelin << std::endl;
}
