#include <iostream>
#include <cmath>

struct Point {
    int x, y;

    // Overloading + operator for point addition
    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y};
    }

    auto operator<=>(const Point& p) const {
        if (auto cmp = x <=> p.x; cmp != 0) return cmp; // Compare x values first
        return y <=> p.y; // Compare y values if x are equal
    }

    // Overloading == operator for point comparison
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    // Overloading != operator for point comparison
    bool operator!=(const Point& p) const {
        return !(*this == p); // Reuse the == operator
    }

    // Overloading < operator for point comparison (lexicographical order)
    bool operator<(const Point& p) const {
        return (x < p.x) || (x == p.x && y < p.y); // Compare x first, then y
    }

    // Overloading <= operator for point comparison (lexicographical order)
    bool operator<=(const Point& p) const {
        return (*this < p) || (*this == p); // Reuse the < and == operators
    }

    // Overloading > operator for point comparison
    bool operator>(const Point& p) const {
        return !(*this <= p); // Reuse the <= operator
    }

    // Overloading >= operator for point comparison
    bool operator>=(const Point& p) const {
        return !(*this < p); // Reuse the < operator
    }

    // Overload subscript operator (const version)
    int operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Index out of range: valid indices are 0 and 1.");
    }

    // Overload subscript operator (non-const version)
    int& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Index out of range: valid indices are 0 and 1.");
    }


    // Conversion operator to int (returns the sum of x and y)
    operator int() const {
        return x + y; // Example: Sum of x and y
    }

    // Conversion operator to double (returns Euclidean distance from origin)
    operator double() const {
        return std::sqrt(x * x + y * y); // Example: Distance from origin
    }

    // Static utility function (not an operator)
    static void printPoint(const Point& p) {
        std::cout << "Static call on Point (" << p.x << ", " << p.y << ")" << std::endl;
    }

    // Another static utility function
    static int sumCoordinates(const Point& p) {
        return p.x + p.y; // Example: returns sum of x and y
    }

        // Prefix increment operator
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Postfix increment operator
    Point operator++(int) {
        Point temp = *this; // Save the current state
        ++(*this); // Use prefix increment
        return temp; // Return the old state
    }

    // Prefix decrement operator
    Point& operator--() {
        --x;
        --y;
        return *this;
    }

    // Postfix decrement operator
    Point operator--(int) {
        Point temp = *this; // Save the current state
        --(*this); // Use prefix decrement
        return temp; // Return the old state
    }

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }


};

int main() {
    Point p1{1, 2}, p2{2, 3};

    // Test + operator
    Point p3 = p1 + p2;
    std::cout << "p1 + p2 = (" << p3.x << ", " << p3.y << ")" << std::endl;

    // Test comparison operators
    std::cout << std::boolalpha; // Enable bool printing as true/false
    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
    std::cout << "p1 != p2: " << (p1 != p2) << std::endl;
    std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
    std::cout << "p1 <= p2: " << (p1 <= p2) << std::endl;
    std::cout << "p1 > p2: " << (p1 > p2) << std::endl;
    std::cout << "p1 >= p2: " << (p1 >= p2) << std::endl;


    auto result = p1 <=> p2;
    if (result < 0) {
        std::cout << "p1 is less than p2\n";
    } else if (result > 0) {
        std::cout << "p1 is greater than p2\n";
    } else {
        std::cout << "p1 is equal to p2\n";
    }

    // Test out-of-range access
    try {
        std::cout << p1[2]; // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Use conversion to int
    int sum = p1; // Conversion to int (sum of x and y)
    std::cout << "Sum of x and y: " << sum << std::endl;

    // Use conversion to double
    double distance = p1; // Conversion to double (distance from origin)
    std::cout << "Distance from origin: " << distance << std::endl;

        // Static utility function usage
    Point::printPoint(p1); // Static call on point

    // Static utility function usage
    std::cout << "Static sum of x and y: " << Point::sumCoordinates(p1) << std::endl;

    // Test prefix increment
    ++p1;
    std::cout << "After prefix increment: (" << p1[0] << ", " << p1[1] << ")" << std::endl;

    // Test postfix increment
    p1++;
    std::cout << "After postfix increment: (" << p1[0] << ", " << p1[1] << ")" << std::endl;

    // Test prefix decrement
    --p1;
    std::cout << "After prefix decrement: (" << p1[0] << ", " << p1[1] << ")" << std::endl;

    // Test postfix decrement
    p1--;
    std::cout << "After postfix decrement: (" << p1[0] << ", " << p1[1] << ")" << std::endl;


    return 32;
}
