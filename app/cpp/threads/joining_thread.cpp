/**
 * --------------------------------------------------------------------------------
 * Credit / Remark: :
 * This source code was inspired by C++ asynchronous programming books and online
 * examples. Portions of the code (e.g., thread examples, lambda usage) are adapted
 * for learning and practice purposes.
 *
 * Author of this adaptation: Ko Thein
 * Purpose: Practice and demonstration of C++ std::thread, lambdas, function objects,
 *          and member function threading.
 *
 * Note:
 * - Original ideas and examples are not my own.
 * - This code is intended solely for educational purposes.
 *
 * --------------------------------------------------------------------------------
*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void func() {
    std::this_thread::sleep_for(1s);
}

int main() {
    using std::cout;
    using std::endl;

    std::thread t1;
    cout << "Is t1 joinable? " << t1.joinable() << endl;
    std::thread t2(func);
    t1.swap(t2);

    cout << "Is t1 joinable? " << t1.joinable() << endl;
    cout << "Is t2 joinable? " << t2.joinable() << endl;

    t1.join();
    cout << "Is t1 joinable? " << t1.joinable() << endl;

    return 0;
}
