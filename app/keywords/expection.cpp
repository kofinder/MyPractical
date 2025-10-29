#include <string>
#include <vector>
#include <iostream>

// ❌ NOT SAFE: may throw an exception
void riskFunction() {
    std::string s = "hello";
    s.at(10);  // at() can throw std::out_of_range if index is invalid
}

// ✅ SAFE: trivial function, guaranteed not to throw
int sum(int a, int b) noexcept {
    return a + b;
}

// ✅ SAFE: constructors and destructors should often be noexcept
struct MyStruct {
    int x;
    MyStruct() noexcept = default;  // trivial constructor
    ~MyStruct() noexcept = default; // trivial destructor
};

// ✅ CONDITIONAL noexcept: depends on template type T
template <typename T>
void create(T t) noexcept(noexcept(T())) {
    T obj; // noexcept only if T() is noexcept
}

int main() {
    // Unsafe function may throw
    try {
        riskFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    // Safe functions
    int result = sum(10, 20);
    std::cout << "Sum: " << result << "\n";

    MyStruct s;
    create<int>(42); // int() is noexcept, so safe

    return 0;
}
