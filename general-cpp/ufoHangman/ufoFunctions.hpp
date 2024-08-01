//
// Created by zsazu on 2022-01-31.
//

#ifndef BASICS_UFOHANGMAN_UFOFUNCTIONS_HPP_
#define BASICS_UFOHANGMAN_UFOFUNCTIONS_HPP_
#include <vector>
void showMisses(int misses);
void greetUser();
void endGame(std::string answer, std::string codeword);
void showStatus(std::vector<char> incorrect, std::string answer);
#endif //BASICS_UFOHANGMAN_UFOFUNCTIONS_HPP_
