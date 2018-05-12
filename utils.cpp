//
// Created by Drasik on 5/12/2018.
//
#include <random>
#include <chrono>
using namespace std;

int randint(int from, int to){
    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    static default_random_engine generator(seed);
    uniform_int_distribution<> dis(from, to);
    return dis(generator);
}