#include <iostream>
#include <string>
#include <string_view>


int main() {

    std::string str = "hello world"; // new memory allocation + copy
    std::string_view str1 = "hello world"; // only the refrence

    std::cout << str1.size() << std::endl;
    std::cout << str.size();


    return 0;
}