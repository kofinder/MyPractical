#include <iostream>
#include <type_traits>
#include <utility> // For std::declval

using namespace std;

// Forward declaration of template structure A
template<typename T, typename Enable = void>
struct A;

// Specialization for signed types
template<typename T>
struct A<T, std::enable_if_t<std::is_signed_v<T>>> {
    // This specialization is for signed types
};

// Specialization for unsigned types
template<typename T>
struct A<T, std::enable_if_t<!std::is_signed_v<T>>> {
    // This specialization is for unsigned types
};

// Structure containing member variables and type alias
struct ExampleStruct {
    static int staticValue; // Static member
    int instanceValue;       // Instance member
    using type = int;        // Type alias for int
};

// Trait to check for presence of static member 'x'
template<typename T, typename Enable = void>
struct has_static_x : std::false_type {};

template<typename T>
struct has_static_x<T, decltype((void) T::staticValue)> : std::true_type {};

// Trait to check for presence of instance member 'y'
template<typename T, typename Enable = void>
struct has_instance_y : std::false_type {};

template<typename T>
struct has_instance_y<T, decltype((void) std::declval<T>().instanceValue)> : std::true_type {};

// Helper to create void types
template<typename...>
using void_t = void; // This is included in C++17 <utility>

// Trait to check for presence of type alias 'type'
template<typename T, typename Enable = void>
struct has_type : std::false_type {};

template<typename T>
struct has_type<T, std::void_t<typename T::type>> : std::true_type {};

// Helper to determine if a type can be streamed to ostream
template<typename T>
using EnableStreamOutput = decltype(std::declval<std::ostream&>() << std::declval<T>());

template<typename T, typename Enable = void>
struct is_stream_supported : std::false_type {};

template<typename T>
struct is_stream_supported<T, EnableStreamOutput<T>> : std::true_type {};

// Example usage of is_stream_supported
struct Streamable {
    friend ostream& operator<<(ostream& os, const Streamable&) {
        os << "Streamable object";
        return os;
    }
};

int ExampleStruct::staticValue = 42; // Definition of static member

int main() {
    // Check for static member 'x'
    cout << "Has static 'x' in ExampleStruct: " 
         << has_static_x<ExampleStruct>::value << endl; // Expected output: 1 (true)

    // Check for instance member 'y'
    cout << "Has instance 'y' in ExampleStruct: " 
         << has_instance_y<ExampleStruct>::value << endl; // Expected output: 1 (true)

    // Check for type alias
    cout << "Has type alias 'type' in ExampleStruct: " 
         << has_type<ExampleStruct>::value << endl; // Expected output: 1 (true)

    // Check if Streamable is stream supported
    cout << "Is Streamable stream supported: " 
         << is_stream_supported<Streamable>::value << endl; // Expected output: 1 (true)

    return 0;
}
