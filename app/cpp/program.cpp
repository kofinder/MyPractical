#include <vector>
#include <iostream>
using namespace std;


int main() {

    // vector<vector<vector<int>>> vec = [...]
    std::vector<std::vector<std::vector<int>>> vec = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    // vector<vector<int>> a = vec::get(0);
    std::vector<std::vector<int>> a = vec.at(0);

    // vector<int> b = a::get(1);
    std::vector<int> b = a.at(1);

    // int y = b::get(0);
    int y = b.at(0);

    std::cout << y << std::endl;  // prints 30

    return 0; 
}
