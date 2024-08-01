//
// Created by zsazu on 2022-01-29.
//
#include <iostream>
using namespace std;
/*fizzBuzz:
 * multiples of 3: fizz
 * multiples of 5: buzz
 * multiples of both 3 and 5: fizzbuzz*/
int main(){
  for(int i=0; i<=100; i++){
    if(i%3 == 0) {
      cout<<"fizz"<<endl;
    }
    else if (i%5 == 0){
      cout<<"buzz"<<endl;
    }
    else if (i%5==0 && i%3==0){
      cout<<"fizzbuzz"<<endl;
    }
    else{
      cout<<i<<endl;
    }
  }
}