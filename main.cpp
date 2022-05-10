#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "maybe/maybe.hpp"
#include "logMonad/logs.hpp"


Maybe<int> addOne(int a){
  return Just<int>(a+1);
}
Maybe<int> doubleIt(int a){
  return Just<int>(a*2);
}
Maybe<int> maybeDiv (int a, int b){
  if(b == 0) return Nothing<int>();
  return Just<int>(a/b);
}


int main() {

  std::cout << maybeDiv(9, 3).run(addOne).run(doubleIt) << endl;

  return 0;
}
