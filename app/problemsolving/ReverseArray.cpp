#include <iostream>

/*
********************************************************************************
* Reverse Array using Tail Recursion
* Purpose: Reverse an array in place
* Inputs:
*   array  - array of elements
*   start  - starting index (0)
*   end    - ending index (size-1)
* Output: array reversed in place
* Time Complexity: O(n)
* Space Complexity: O(n) for recursion stack (O(1) if tail call optimized)
********************************************************************************

    PSEUDOCODE reverse_tail(array, start, end)
        if start >= end then
            return

        swap(array[start], array[end])
        
        reverse_tail(array, start + 1, end - 1)

    end PSEUDOCODE

*/

// bit manipulation
void swap(int &a, int &b) { a = a + b - (b = a); }


void reverse_array_head_recursion(int array[], int start, int end) {
    if(start >= end) return;

    reverse_array_head_recursion(array, start + 1, end -1);

    swap(array[start], array[end]);
}


void reverse_array_tail_recursion(int array[], int start, int end) {
    if(start >= end) return;

    swap(array[start], array[end]);

    reverse_array_tail_recursion(array, start + 1, end -1);
}

int main() {

    using namespace std;

    int array[] = { 1, 2, 3, 4, 5 };

    int size = sizeof(array) / sizeof(array[0]);

    reverse_array_head_recursion(array, 0, size - 1);

    for(int num: array)  cout << num << endl;

    return 0;
}