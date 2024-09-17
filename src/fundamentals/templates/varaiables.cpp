#include <iostream>
#include <type_traits>

// Variable template for pi
template<typename T>
constexpr T pi{ 3.1415926535897932385 };

// Function template to calculate the area of a circle
template<typename T>
T circular_area(T r) {
    return pi<T> * r * r;
}

int main() {
    // Calculate area with float
    float radius_f = 3.3f;
    float area_f = circular_area(radius_f);
    std::cout << "Area with float radius: " << area_f << std::endl;

    // Calculate area with double
    double radius_d = 3.3;
    double area_d = circular_area(radius_d);
    std::cout << "Area with double radius: " << area_d << std::endl;

    // Uncommenting the following line will cause a compile-time error due to narrowing conversion
    // int radius_i = 3;
    // auto area_i = circular_area(radius_i);

    return 0;
}
