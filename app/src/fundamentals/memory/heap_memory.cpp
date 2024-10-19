#include <iostream>



int main() {
    // Allocate memory for an integer on the heap using malloc
    // malloc returns a void* which needs to be cast to int*
    int* x = (int*)malloc(sizeof(int));
    free(x);
    

    // Allocate memory for an integer on the heap using 'new'
    // 'new' automatically returns an int* (no cast needed)
    int* y = new int;
    delete y;

    unsigned* buffer2 = new unsigned[2];
    double* z = new (buffer2) double;
    delete[] buffer2; // ok
    delete[] z; // ok, but can be Invalid free/ delete/ reallocate


    // Important differences between malloc and new:
    // 1. 'malloc' is a C function and requires manual casting to the correct type.
    //    It allocates uninitialized memory.
    // 2. 'new' is a C++ operator and does not require casting. It also calls the constructor
    //    for classes, whereas 'malloc' does not. Here, 'new int' allocates and initializes the
    //    memory (default initialization in this case).
    
    // In real programs, you should free the memory allocated by 'malloc' and 'new':
    // free(x); // Free the memory allocated by malloc
    // delete y; // Free the memory allocated by new

    // Return value of main. The return type of main is int, but here a float (3.6) is being
    // returned. The return value will be truncated to an integer, so this effectively returns 3.
    return (int)3.6; // type cast from double (3.6) to int, resulting in 3

}