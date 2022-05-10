#include <iostream>
#include <string>
#include <sstream>
#include "maybe.hpp"

// Constructor 1 de la monada
template <typename T>
Maybe<T> Just(T a){
  Maybe<T> res;
  res.isNothing = false;
  res.data = a;
  return res;
}
template Maybe<int> Just(int);

// Constructor 2 de la monada
template <typename T>
Maybe<T> Nothing(){
  Maybe<T> res;
  res.isNothing = true;
  return res;
}
template Maybe<int> Nothing();

// >>= 
template <typename T>
Maybe<T> Maybe<T>::run(Maybe<T> f(T)){
  if(!isNothing){
    Maybe res = f(data);
    res.isNothing = false;
    return res;
  }
  return Nothing<T>();
}
template Maybe<int> Maybe<int>::run(Maybe<int> f(int));

// fromMaybe (<- ?)
template <typename T>
T fromMaybe(T def, Maybe<T> a){
    if(a.isNothing){
        return def;
    }
    return a.data;
}
template int fromMaybe(int, Maybe<int>);


// sobrecarga de operador << (para mostrar por pantalla)
template <typename T>
std::ostream& operator << (std::ostream &out, Maybe<T> z){
  if(z.isNothing){
    out<<"Nothing";
  }else{
    out<<"Just "<<z.data;
  }
  return out;
}
template std::ostream& operator << (std::ostream &out, Maybe<int> z);


