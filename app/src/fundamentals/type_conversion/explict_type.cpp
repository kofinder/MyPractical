#include <iostream>
#include <cstdlib> // For malloc


int main() {

    // STATIC CAST
    char a[] { 1, 2, 3, 4, 5};
    int* b = (int*)a;
    // int* c = static_cast<int*> (a); // unsafe conversion


    // CONST CAST
    const int x = 80;
    // const_cast<int>(x) = 3; // undefined behavior


    // REINTERPRET CASE (bit-level conversion)
    float f = 3.0f;
    int fcast = reinterpret_cast<int&>(f);
    std::cout << "fcaset output ==:==>" << fcast;

    int* ptr = new int;
    int ptrcast = reinterpret_cast<size_t>(ptr);
    std::cout << "ptrcast output ==:==>" << ptrcast;


    // ARRAY RESHAPING
    int a[3][4] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12} 
    };

    // Reinterpret cast `a` to different types
    int (&b)[2][6] = reinterpret_cast<int (&)[2][6]>(a);
    int (*c)[6] = reinterpret_cast<int (*)[6]>(a);

    // std::cout << "Using b (reference):" << std::endl;
    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 6; ++j) {
    //         std::cout << b[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    // Print using `c`
    std::cout << "Using c (pointer):" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }


    
    return 0;
}