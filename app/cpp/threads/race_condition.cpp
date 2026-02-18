/**
 * --------------------------------------------------------------------------------
 * Race Condition Demonstration
 *
 * - Shared variable `counter` is incremented by multiple threads.
 * - The final value may be **less than expected** due to concurrent access.
 *
 * Note about Java:
 * - In Java, declaring a variable `volatile` ensures **visibility** across threads,
 *   but it does NOT guarantee atomicity of compound operations (like counter++).
 * - In C++, `volatile` is not used for thread synchronization. Instead, use:
 *      - std::mutex for locking
 *      - std::atomic for atomic operations
 * --------------------------------------------------------------------------------
*/

#include <iostream>
#include <thread>

// Shared variable between threads
int counter = 0;

void increment(int id) {

    for (int i = 0; i < 10000; i++) {

        counter++; // Race condition here

        // tiny delay to force thread switching
        if (i % 1000 == 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
        
    }

    std::cout << "Thread " << id << " done\n";
}

int main() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}
