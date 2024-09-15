#include <iostream>
#include <cstdlib> // For malloc

constexpr int square(int value) {
    return value * value;
}


int main() {
    const int x = 10;
    // x = 50; // const value never change after initialization

    const int* y =(int*)malloc(40);
    y = &x;

    std::cout << "X is ==:==>" << x;

    std::cout << "Y is ==:==>" << *y;

    std::cout << "square is ==:==>" << square(4);
    
}