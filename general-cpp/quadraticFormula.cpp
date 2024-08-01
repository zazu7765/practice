//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double a,b,c;
  double firstRoot, secondRoot;

  cout << "Quadratic Formula" <<endl;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  cout << "Enter c: ";
  cin >> c;

  firstRoot = (-b + sqrt(b*b - 4*a*c))/(2*a);
  secondRoot = (-b - sqrt(b*b-4*a*c))/(2*a);

  cout << "Your roots: " << firstRoot << " & " << secondRoot <<endl;
  return 0;
}
