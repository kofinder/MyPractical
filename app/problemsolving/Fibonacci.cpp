#include <iostream>

/*

********************************************************************************
* Fibonacci = The Fibonacci sequence is a series of numbers where each number is 
                the sum of the two numbers before it.
********************************************************************************

PSEUDOCODE fibonacci(n)

    if n == 0 then 
        return 0
    end if

    if n == 1 then 
        return 1
    end if

    return fibonacci(n - 1) + fibonacci(n - 2)

end PSEUDOCODE

*/


// Head recursion: work done AFTER recursion
int fibonacci_head_recursion(int n) {

    if(n == 0) return 0; // base case

    if(n == 1) return 1; // base case

    int fib = fibonacci_head_recursion(n - 1);

    int fib2 = fibonacci_head_recursion(n - 2);

    int result = fib + fib2;

    return result;
}

// Tail recursion: work done DURING recursion
int fibonacci_tail_recursion(int n, int a = 0, int b = 1) {

    if(n == 0) return a; // base case

    if(n == 1) return b; // base case

    return fibonacci_tail_recursion(n - 1, b, a + b);
}


int main() {
    using std::cout;
    using std::endl;    

    cout << fibonacci_tail_recursion(10) << endl;

    return 0;
}