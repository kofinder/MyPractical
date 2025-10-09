
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOfTwo(int n) {
    if(n == 1) return true;

    if(n <= 0 || n % 2 != 0) return false;

    return isPowerOfTwo(n/2);
}

using namespace std;

int main() {

    cout << isPowerOfTwo(20) << endl;

    return 0;
}