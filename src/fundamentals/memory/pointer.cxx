#include <iostream>

void f(int* x) {} // X value can be nullptr;

void g(int& y) {} // Y value never nullptr


void fnArgWithRef(int (&array)[3]) {
    std::cout<<sizeof(array);
};

void fnArg(int array[]) {
    std::cout<<sizeof(array); // 
}


void checkRefrenceArray() {
    int A[4];
    int (&B)[4] = A; // ok, reference to array
    int C[10][3];
    int (&D)[10][3] = C; // ok, reference to 2D array
    auto c = new int[3][4]; // type is int (*)[4]
    // read as "pointer to arrays of 4 int"
    // int (&d)[3][4] = c; // compile error
    // int (*e)[3] = c; // compile error
    int (*f)[4] = c; // ok
    int array[4];
    // &array is a pointer to an array of size 4
    int size1 = (&array)[1] - array;
    int size2 = *(&array + 1) - array;
    std::cout << size1; // print 4
    std::cout << size2; // print 4
}

int main() {

    checkRefrenceArray();

    std::cout << "CHECK ARRAYS \n";

    int x = 5;

    int& y = x;

    int& z = y;

    int* i = &z;


    ++y;

    ++*i;


    int* numPtr = nullptr;
    f(numPtr); // 
    // g(&numPtr); // compile time error

    int num = 300;
    f(&num);
    g(num);

    f(0); // why it is not work
    // g(0); // cannot assign due to allow refrence address



    int A[3], B[4];
    int* C = A;

    //------------------------------------------------------
    fnArgWithRef(A); // ok
    // fnArgWithRef(B); // compile error B has size 4
    // fnArgWithRef(C); // compile error C is a pointer

    // fnArg(A);
    // fnArg(B);
    // fnArg(C);

    std::cout << "Y value ====>" << y;
    std::cout << "\n X value ====>" << x;
    std::cout << "\n Z value ====>" << z;
    std::cout << "\n I value ====>" << *i;

    return 0;
}