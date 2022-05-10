#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "logs.hpp"


// >>=
template <typename T>
logMonad<T> logMonad<T>::run(logMonad<T> f(T)){
    logMonad b = f(data);

    stringstream newLog;
    newLog << log << b.log;
    b.log = newLog.str();

    return b;
}
template logMonad<int> logMonad<int>::run(logMonad<int> f(int));



// Constructor de la monada
template <typename T>
logMonad<T> wrapWithLogs(T a){
    logMonad<T> res;
    res.data = a;

    stringstream log;
    log << a << ".";
    res.log = log.str();

    return res;
}
template logMonad<int> wrapWithLogs(int);

// sobrecarga de operador << (para mostrar por pantalla)
template <typename T>
std::ostream& operator << (std::ostream &out, logMonad<T> a){
    cout << a.data << ": " << a.log << endl;
    return out;
}
template std::ostream& operator << (std::ostream &out, logMonad<int> z);