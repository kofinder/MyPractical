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

/*
    Time → 
    main() starts
    │
    ├─> JthreadWrapper t1 created  ──> t1 thread starts running func("<<one>>")
    │
    ├─> JthreadWrapper t2 created  ──> t2 thread starts running func("<<two>>")
    │
    ├─> JthreadWrapper t3 created  ──> t3 thread starts running func("<<three>>")
    │
    ├─> main thread sleeps for 2s
    │
    ├─> Threads finish their 1s work
    │     t1, t2, t3 print "is ended"
    │
    ├─> main thread prints: "Main thread is exiting....."
    │
    ├─> Scope ends → destructors called in reverse order
    │     ┌─────────── t3 destructor joins t3 → prints "Thread <<three>> being destroyed"
    │     │
    │     ├─────────── t2 destructor joins t2 → prints "Thread <<two>> being destroyed"
    │     │
    │     └─────────── t1 destructor joins t1 → prints "Thread <<one>> being destroyed"
    │
    Program fully exits
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include <memory>

//--------------------------------------------------------
// Thread wrapper class using RAII (std::jthread)
//--------------------------------------------------------
class JthreadWrapper {

    public:

        JthreadWrapper(
            std::function<void(const std::string&)> func,
            const std::string& str
        ) : t(func, str), name(str) {
            std::cout << "Thread " << name << " being created" << std::endl;
        }
        ~ JthreadWrapper() {
            std::cout << "Thread " << name << " being destroyed" << std::endl;
        }

    private:
        std::jthread t;
        std::string name;
};


//--------------------------------------------------------
// Thread function
//--------------------------------------------------------
using namespace std::chrono_literals;
void func(const std::string& name) {
    std::cout << "Thread " << name << " started! " <<std::endl;
    std::this_thread::sleep_for(1s); // Simulate work
    std::cout << "Thread " << name << " finished! " <<std::endl;
}

int main() {

    // Stack allocation (automatic RAII, destructors called LIFO)
    std::cout << "=== Stack Allocation Example (RAII, LIFO destruction) ===" << std::endl;
    JthreadWrapper t1(func, "<<one>>");
    JthreadWrapper t2(func, "<<two>>");
    JthreadWrapper t3(func, "<<three>>");
    std::this_thread::sleep_for(2s); // Allow threads to run
    std::cout << "Main thred is exixting..... " << std::endl;


    // Heap allocation using unique_ptr (automatic RAII, safe destruction)
    // std::cout << "\n=== Heap Allocation with smart pointers (RAII) ===" << std::endl;
    // Heap allocation with smart pointer (Automatic description) LIFO(stack)
    // auto ht1 = std::make_unique<JthreadWrapper>(func, "<<one>>");
    // auto ht2 = std::make_unique<JthreadWrapper>(func, "<<two>>");
    // auto ht3 = std::make_unique<JthreadWrapper>(func, "<<three>>");
    // std::this_thread::sleep_for(2s); // Allow threads to run
    // std::cout << "Main thred is exixting..... " << std::endl;
    

    // Heap allocation with manual destruction (less safe)
    // std::cout << "\n=== Heap Allocation with manual delete (unsafe) ===" << std::endl;
    // JthreadWrapper* mt1 = new JthreadWrapper(func, "<<one>>");
    // JthreadWrapper* mt2 = new JthreadWrapper(func, "<<two>>");
    // JthreadWrapper* mt3 = new JthreadWrapper(func, "<<three>>");
    // std::this_thread::sleep_for(2s); // Allow threads to run
    // std::cout << "Main thred is exixting..... " << std::endl;
    // delete mt1; 
    // delete mt2;
    // delete mt3;

    return 0;
}

