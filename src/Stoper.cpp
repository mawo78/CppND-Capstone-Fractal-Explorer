#include "Stoper.h"
#include <iostream>

using namespace std::chrono;

Stoper::Stoper() : m_start(high_resolution_clock::now()) {}

Stoper::~Stoper() {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - m_start);
    std::cout << "Calculation time:" << duration.count() / 1000.0 << std::endl;
}