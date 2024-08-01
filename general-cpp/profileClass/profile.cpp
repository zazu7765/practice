//
// Created by zsazu on 2022-02-01.
//
#include <iostream>
#include "profile.hpp"
Profile::Profile(string newName, int newAge, string newCity, string newCountry, string newPronouns) {
  name = newName;
  age = newAge;
  city = newCity;
  country = newCountry;
  pronouns = newPronouns;
}

string Profile::viewProfile() {
  string profileBio = "Name: " + name;
  profileBio+= "\nAge: " + to_string(age);
  profileBio+= "\nPronouns: " + pronouns;
  profileBio+= "\nCity: " + city;
  profileBio+= "\nCountry: " + country;
  profileBio+= "\nHobbies: ";
  for(int i = 0; i < hobbies.size(); i++){
    profileBio+="\n   " + hobbies[i];
  }
  return profileBio;
}
void Profile::addHobby(string newHobby) {
  hobbies.push_back(newHobby);
}

