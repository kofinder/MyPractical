#include <iostream>

using namespace std;


/*

********************************************************************************
* Prime = exactly two factors, cannot be divided evenly by anything else.
********************************************************************************

PSEUDOCODE IsPrime(n):

    IF n <= 1 THEN
        RETURN "Not Prime"
    END IF

    IF n == 2 OR n == 3 THEN
        RETURN "Prime"
    END IF

    IF n MOD 2 == 0 OR n MOD 3 == 0 THEN
        RETURN "Not Prime"
    END IF

    i ← 5
    WHILE i * i <= n DO
        IF n MOD i == 0 OR n MOD (i + 2) == 0 THEN
            RETURN "Not Prime"
        END IF

        i ← i + 6
    END WHILE

    RETURN "Prime"

END PSEUDOCODE

*/


bool isPrimeTailRecursive(int n, int i = 2) {

    if (n <= 1) return false;       // 0 and 1 are not prime

    if (i * i > n) return true;     // no divisors found → prime

    if (n % i == 0) return false;   // divisible → not prime

    return isPrimeTailRecursive(n, i + 1); // check next i
}

bool isPrimeHeadRecursive(int n, int i = 2) {

    if (n <= 1) return false;   // 0 and 1 are not prime

    if (i * i > n) return true;  // no divisors found → prime

    bool isPrime = isPrimeHeadRecursive(n, i + 1);

    if (n % i == 0) return false; // divisible → not prime

    return isPrime;
}


bool isPrimeIteration(int n) {

    if(n <= 1) return false;  // 0 and 1 are not prime

    int i = 2;
    
    do {

        if (i * i > n) break; // no divisors found → prime

        if (n % i == 0) return false; // divisible → not prime

        i++;

    } while (i * i < n);

    return true;
}


// optimization with bitwise operator
bool checkPrimeNumber(int n) {
    if (n <= 1) return false;          // 0 and 1 are not prime
    if (n == 2) return true;           // 2 is prime
    if ((n & 1) == 0) return false;    // even numbers > 2 are not prime

    int i = 3;
    while (i * i <= n) {
        if (n % i == 0) return false;  // divisible → not prime
        i += 2; // check only odd numbers
    }

    return true;
}


 

int main() {
    int number = 3;
    if (isPrimeIteration(number)) cout << number << " is a prime number." << endl;
    else cout << number << " is not a prime number." << endl;
    return 0;
}


