#include <iostream>

struct A {
    A() {}
    A(int x) {}
    A(int x, int y) {}
};


struct B {
    explicit B() {}
    explicit B(int x) {}
    explicit B(int x, int y) {}

};

void checkA(const A&) {}

void checkB(const B&) {}


int main() {

    A a = {};

    A a1(2);

    A a2 {3, 4};

    A a3 = {4, 5};

    checkA({});

    checkA(2);

    checkA({2, 3});

    B b = {}; // error due to implict conversion

    B b4 = {3, 4}; // error due to implict conversion

    B b3 = 3; // error due to implict conversion

    checkB({}); // error due to implict conversion

    checkB(2); // error due to implict conversion

    checkB({2, 3}); // error due to implict conversion


    B b1(1);

    B b2 { 3, 4 };

    B b6 = (B) 1; // explicit cast 

    checkB(B{1});

    return 0;
}