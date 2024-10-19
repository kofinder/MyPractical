#include <iostream>

struct Array {
    int size;
    int* array;

    Array(int _size): size{_size} {
        array = new int[_size];
    }


    // copy constructor (initializer lit)
    Array(const Array& arr): size{arr.size} {
        array = new int[size];
        for(int i = 0; i < size; i++) {
            array[i] = arr.array[i];
        }
    }

    ~Array() {
        delete[] array;
    }

};

struct A {
    A() {}

    A(const A& obj) { std::cout << "expensive copy" << std::endl; }
    
    ~A() {}
};

struct B : A {
    B() {}

    B(const B& obj) { std::cout << "cheap copy" << std::endl; }

    ~B() {}

};

void f1(B b) {}

void f2(A a) {}

int main() {
    Array arr{100};

    Array arr1(arr); // direct copy initialization

    Array arr2 {arr}; // direct copy initialization

    Array arr3 = arr; // copy initialization

    Array arr4 = { arr }; // copy list initialization

    B b1;
    
    f1(b1); // cheap copy

    f2(b1); // expensive copy!! It calls A(const A&) implicitly

    return 0;
}