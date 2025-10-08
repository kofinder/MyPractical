#include <iostream>
#include <utility>
#include <string>

int main() {

    constexpr auto lambda = [] <typename T>(T&& x) -> decltype(auto) {
        return std::forward<T>(x);
    };

    std::string s = "Hello";
    auto t = lambda(5);           // lvalue → returns std::string&

    std::cout << t << "\n";
}
