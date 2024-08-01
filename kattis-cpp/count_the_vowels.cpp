#include <algorithm>
#include <iostream>
#include <string>
std::string toVowel;
int main(){
  const std::string& vowels = "aeiouAEIOU";
  std::getline(std::cin, toVowel);
  const auto vowelLambda = [&vowels](const char c){
    return vowels.find(c)!=std::string::npos;
  };
  auto count = std::count_if(toVowel.cbegin(), toVowel.cend(), vowelLambda);
  std::cout<<count<<"\n";
}
