#pragma once
#include <iostream>

void logger(int p) {
    std::cout << __FILE__ << ":" << __LINE__ <<std::endl; // print 'source.cpp:4'
    std::cout << __FUNCTION__<<std::endl;  // print 'f'
    std::cout << __func__<<std::endl;  // print 'f'
}

template<typename T>
float g(T p) {
    std::cout << __PRETTY_FUNCTION__; // print 'float g(T) [T = int]'
    return 0.0f;
}
