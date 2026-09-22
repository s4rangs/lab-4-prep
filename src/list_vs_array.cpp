#include <cstddef> 
#include <cstdint> // uint64_t
#include <iostream> 
#include <list> 
#include <random> // mt19937_64
#include <vector> 

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    std::mt19937_64 rng(0);
    std::list<uint64_t> list;
    Timer timer;

    for (size_t i = 0; i < SIZE; ++i) {
        list.push_back(rng());
    }
    std::cout << "list insert " << timer.click<Timer::Micros>() << " microseconds\n";

    rng.seed(0);


    std::vector<uint64_t> vector;
    Timer timer2;

    for (size_t i = 0; i < SIZE; ++i) {
        vector.push_back(rng());
    }

    std::cout << "vector without reserve " << timer2.click<Timer::Micros>() << " microseconds\n";

    rng.seed(0);


    std::vector<uint64_t> vectorReserve;
    vectorReserve.reserve(SIZE);
    Timer timer3;

    for (size_t i = 0; i < SIZE; ++i) {
        vectorReserve.push_back(rng());
    }

    std::cout << "vector with reserve " << timer3.click<Timer::Micros>() << " microseconds\n";
    uint64_t listSum = 0;

    // list sum        
    Timer timer4;

    for (uint64_t value : list) {
        listSum += value;
    }

    std::cout << "list sum " << listSum << " (" << timer4.click<Timer::Micros>() << " microseconds)\n";

    uint64_t vectorSum = 0;

    // vector sum
    Timer timer5;

    for (uint64_t value : vector) {
        vectorSum += value;
    }

    std::cout << "vector sum without reserve " << vectorSum << " (" << timer5.click<Timer::Micros>() << " microseconds)\n";


    uint64_t vectorReserveSum = 0;

    // reserved vector sum
    Timer timer6;

    for (uint64_t value : vectorReserve) {
        vectorReserveSum += value;
    }

    std::cout << "vector sum with reserve " << vectorReserveSum << " (" << timer6.click<Timer::Micros>() << " microseconds)\n";
    
    return 0;
}
