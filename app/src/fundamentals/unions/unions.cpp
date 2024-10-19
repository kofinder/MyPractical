#include <iostream>

union Json {
    char ch;
    int num;
} json; // 4 bytes

union Map {
    char ch;
    int num;
    double decimal;
}; // 4 bytes


int main() {
    json.ch = 'U';
    json.num = 100;

    Map mp;
    mp.ch = 1;
    mp.num = 100;
    mp.decimal = 1.44;

    std::cout << sizeof(Json) << std::endl;
    std::cout << sizeof(Map) << std::endl;
}