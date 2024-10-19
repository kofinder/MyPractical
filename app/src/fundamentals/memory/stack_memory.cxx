#include <iostream>


int* fnPointer() {
    int array[3] = {1, 2, 3};
    return 0; // suprise
}

void fnPassValue(bool x) {
    const char* str = "abc"; // Dynamically allocate memory for "xyz"

    if(x) {
        char xyz[] = "xyz";    // Local array 'xyz' in this block
        str = xyz;             // str now points to the local array 'xyz'
    }

    std::cout << str; // if above contion block execute, must be occurs Illegal memory access
}

int main() {
    std::cout << "HELLO";

    fnPassValue(true);

    // STACK MEMORY (NOT NEED TO DEALLOCATE)
    char buffer[8];
    int* x = new (buffer) int;
    short* y = new (x + 1) short[2];


    // int* ptr = fnPointer();

    // std::cout << ptr[0]; // suprise in term of not showing comple error


    return (int)3.6; // type cast
}