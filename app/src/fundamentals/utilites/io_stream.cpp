#include <iostream>
#include <fstream>
#include <bitset>
#include <iomanip>

long long int fileSize(const char* file_path) {
    std::ifstream fin(file_path);
    fin.seekg(0, std::ios::beg);  // Corrected to std::ios::beg
    std::istream::pos_type start_pos = fin.tellg();

    fin.seekg(0, std::ios::end);  // Corrected to std::ios::end
    std::istream::pos_type end_pos = fin.tellg();

    return end_pos - start_pos;
}

int main() {
    // Call the filSize function and pass the path to the file
    const char* file_path = "example.txt";
    long long int size = fileSize(file_path);  // Call fileSize and store result
    std::cout << "File size of '" << file_path << "' is: " << size << " bytes" << std::endl;


    // Print bit representation of a float value
    std::cout << std::bitset<32>(3.45f) << std::endl;

    // Print integer representation in different number bases
    std::cout << std::dec << 0xF << std::endl;  // Decimal representation of 0xF (15)
    std::cout << std::hex << 16 << std::endl;   // Hexadecimal representation of 16 (10)
    std::cout << std::oct << 8 << std::endl;    // Octal representation of 8 (10)

    // Print the contents of a file
    std::ifstream fin("example.txt");
    if (fin.is_open()) {
        std::cout << fin.rdbuf();  // Print file content
        fin.close();
    } else {
        std::cerr << "Error: Could not open file 'example.txt'\n";
    }
    
    return 0;
}
