#include <iostream>

#include <limits>

#include <cfenv> // // floating point exceptions

#include <cmath>  // For std::fabs


std::string getCxxVersion() {
    if (__cplusplus == 201703L) {
        return "C++17";
    } else if (__cplusplus == 201402L) {
        return "C++14";
    } else if (__cplusplus == 201103L) {
        return "C++11";
    } else if (__cplusplus == 199711L) {
        return "C++98";
    } else if (__cplusplus == 202002L) {
        return "C++20";
    } else if (__cplusplus == 202300L) {
        return "C++23";
    } else {
        return "Unknown C++ version";
    }
}

// struct can use one more variable
struct A {
    char x;
    int y;
} a, b;

// Enumarator can declare inside struct without naming
struct B {
    enum { X, Y };
};


// struct can use insdie funtion
int funA() {
    struct A {
        int t = 40;
    } a;

    return a.t;
};


// struct can use without naming
struct {
    int x = 10;
    int y = 40;
} C;


// struct can use inside struct as anymanous declaration
struct S {
    int z = 500;
    struct {
        int i = 100;
    } x;
};

// Bitfield useage in struct
struct Status {
    int active: 1;
    int inactive: 2;
    int ban: 5;
    int : 0; // reset force to next field
    int subspend: 9;
};

int main() {

    std::cout << "START LEARNING BASIC CONCEPT OF PRATICAL C++ \n" << std::endl;
    std::cout << "C++ Version: " << getCxxVersion() << "\n" << std::endl;
    std::cout << ":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:= \n" << std::endl;

    a.x = 'A';
    a.y = 300;

    b.x = 'B';
    b.y = 400;


    std::cout << "A.x ====>" << a.x << "A.y ====>" << a.y;
    std::cout << "\n B.x ====>" << b.x << "b.y ====>" << a.y;

    std::cout << "\nX: " << B::X << std::endl;  // Output: X: 0
    std::cout << "\nY: " << B::Y << std::endl;  // Output: Y: 1

    std::cout << "C ===>" << C.x;

    std::cout << "\n bitfield size status of " << sizeof(Status);
    std::cout << "\n:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:= \n" << std::endl;
    std::cout << "END LEARNING BASIC CONCEPT OF PRATICAL C++ \n" << std::endl;

    return 42;
}