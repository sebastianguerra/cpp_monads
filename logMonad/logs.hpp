#ifndef logs_hpp
#define logs_hpp

template <typename T>
struct logMonad{
  T data;
  string log;
  logMonad run(logMonad f(T));
};

template <typename T>
logMonad<T> wrapWithLogs(T a);


template <typename T>
std::ostream& operator << (std::ostream &out, logMonad<T> z);

#endif
