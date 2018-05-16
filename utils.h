//
// Created by Drasik on 5/12/2018.
//
#ifndef SDIZO_PROJECT_2_UTILS_H
#define SDIZO_PROJECT_2_UTILS_H

#endif //SDIZO_PROJECT_2_UTILS_H

#include "chrono"
#include "random"
#include <iostream>
using namespace std;

extern int INF;

inline int randint(int from, int to){
    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    static default_random_engine generator(seed);
    uniform_int_distribution<> dis(from, to);
    return dis(generator);
}

//template<class T, typename ReturnType, typename... Args>
//long long int measure(T *object, ReturnType (T::*func)(Args...), Args... args) {
//    chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
//    (object->*func)(args...);
//    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
//    long long int result = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
//    cout << result << "\t";
//    return result;
//}

template <typename OBJECT, typename FUNC, typename... Args>
inline long long measure(OBJECT obj, FUNC func, Args... args)
{
    chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
    (obj.*func)(args...);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    long long int result = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    return result;
}

