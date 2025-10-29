#include <iostream>
#include <thread>
#include <vector>


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

using std::cout;
using std::thread;
using std::vector;

void simpleFunc() {
    cout << "Simple function execution\n";
}

auto lambdaFunc = []() {
    cout << "Lambda function execution\n";
};

class FuncObject {
public:
    void operator()() {
        cout << "Function object execution\n";
    }
};

class NonStaticMemberFunc {
public:
    void simpleFunc() {
        cout << "Non-static member function execution\n";
    }
};

class StaticMemberFunc {
public:
    static void simpleFunc() {
        cout << "Static member function execution\n";
    }
};

int main() {
    thread t1(simpleFunc);
    thread t3(lambdaFunc);

    FuncObject obj;
    thread t4(obj);

    NonStaticMemberFunc nobj;
    thread t5(&NonStaticMemberFunc::simpleFunc, &nobj);

    thread t6(&StaticMemberFunc::simpleFunc);

    thread embeded_lambda_func([]() {
        cout << "Embedded lambda function execution\n";
    });

    // Join all threads
    t1.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    embeded_lambda_func.join();

    return 0;
}
