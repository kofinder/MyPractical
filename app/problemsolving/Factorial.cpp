#include <iostream>

/*

********************************************************************************
* Factorials = Factorials count how many ways something can be arranged or ordered.
********************************************************************************

PSEUDOCODE Factorial(n)

    if n < 0 then return "undefined"

    else if n == 0 or n == 1 then return 1

    else eturn n × Factorial(n - 1)

end PSEUDOCODE

*/


// Head recursion: work done AFTER recursion
int factorial_head_recursion(int n) {

    if(n < 0 || n == 1) return 1; // base case

    int result = factorial_head_recursion(n - 1);

    return n * result;
}

// Tail recursion: work done DURING recursion
int factorial_tail_recursion(int n, int accumulator = 1) {

    if(n < 0 || n == 1) return accumulator; // base case


    return factorial_tail_recursion(n -1, accumulator * n);
}

int main() {
    using std::cout;
    using std::endl;   

    cout << factorial_tail_recursion(5) << endl;

    return 0;
}