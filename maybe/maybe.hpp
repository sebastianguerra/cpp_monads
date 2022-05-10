#ifndef MAYBE_HPP
#define MAYBE_HPP
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
struct Maybe{
  T data;
  bool isNothing;
  Maybe run(Maybe(T));
};

template <typename T>
Maybe<T> Just(T a);

template <typename T>
Maybe<T> Nothing();

template <typename T>
T fromMaybe(T, Maybe<T>);

template <typename T>
std::ostream& operator << (std::ostream &out, Maybe<T> z);

#endif
