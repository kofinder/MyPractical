#include <iostream>

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Integer Addition: " << add(20, 20) << std::endl;
    std::cout << "Double Addition: " << add(4.0, 5.0) << std::endl;
    std::cout << "Float Addition: " << add(3.0f, 4.0f) << std::endl;
    std::cout << "Check again (Integer): " << add(20, 20) << std::endl;

    return 0;
}
