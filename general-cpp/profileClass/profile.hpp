//
// Created by zsazu on 2022-02-01.
//
#include <vector>
#include <string>
using namespace std;
#ifndef BASICS_PROFILECLASS_PROFILE_HPP_
#define BASICS_PROFILECLASS_PROFILE_HPP_
class Profile{
 private:
  string name;
  int age;
  string city;
  string country;
  string pronouns;
  vector<string> hobbies;
 public:
  Profile(string newName, int newAge, string newCity, string newCountry, string newPronouns="they/them");
  string viewProfile();
  void addHobby(string newHobby);
};

#endif //BASICS_PROFILECLASS_PROFILE_HPP_
