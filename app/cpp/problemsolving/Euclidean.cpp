
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOfTwo(int n) {
    if(n == 1) return true;

    if(n <= 0 || n % 2 != 0) return false;

    return isPowerOfTwo(n/2);
}


int main() {

    using std::cout;
    using std::endl;    

    cout << isPowerOfTwo(20) << "\n";

    return 0;
}