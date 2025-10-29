#include <iostream>
#include <thread>
#include <vector>
#include <syncstream> // suprise

/**
 * --------------------------------------------------------------------------------
 * Credit / Remark:
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


#define sync_cout std::osyncstream(std::cout) // suprise

int main() {
    const int repeat_count = 100;

    std::thread embeded_lambda_func_t1([repeat_count]() {
        for (int i = 0; i < repeat_count; i++) {
            sync_cout << "1 " << "2 " << "3 " << "4 " << std::endl;

            // std::ostringstream oss;
            // oss << "1 2 3 4\n";
            // std::cout << oss.str();

        }
    });

    std::thread embeded_lambda_func_t2([repeat_count]() {
        for (int i = 0; i < repeat_count; i++) {
            sync_cout << "5 " << "6 " << "7 " << "8 " << std::endl;

            // std::ostringstream oss;
            // oss << "5 6 7 8\n";
            // std::cout << oss.str();

        }
    });


    embeded_lambda_func_t1.join();
    embeded_lambda_func_t2.join();


    return 0;
}