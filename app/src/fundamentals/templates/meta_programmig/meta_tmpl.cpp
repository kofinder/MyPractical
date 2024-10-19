#include <iostream>

// Compute factorial at compile time using a loop
template<typename T>
constexpr int computeFactorial(T value) {
    T result = 1;
    for (int i = 2; i <= value; i++) {
        result *= i;
    }
    return result;
}

// Calculate log base 2 at compile time using recursion
template<int N>
struct LogBase2 {
    static_assert(N > 0, "N must be greater than zero");  // Ensure valid input
    static constexpr int value = 1 + LogBase2<N / 2>::value;  // Recursive step
};

// Base case specialization for LogBase2
template<>
struct LogBase2<1> {
    static constexpr int value = 0;  // Base case when N = 1
};

// Find the maximum of two integer values at compile time
template<int A, int B>
struct MaxValue {
    static constexpr int value = A > B ? A : B;  // Use ternary to find maximum
};

// Calculate the logarithm of N with respect to any base using recursion
template<int N, int BASE>
struct Logarithm {
    static_assert(N > 0, "N must be greater than zero");        // Ensure valid N
    static_assert(BASE > 0, "Base must be greater than zero");  // Ensure valid base

    // Use MaxValue to avoid division by zero and prevent recursion on N = 0
    static constexpr int Temp = MaxValue<1, N / BASE>::value;
    static constexpr int value = 1 + Logarithm<Temp, BASE>::value;  // Recursive step
};

// Base case specialization for Logarithm when N = 1
template<int BASE>
struct Logarithm<1, BASE> {
    static constexpr int value = 0;  // Base case
};

// Template to unroll loops at compile time
template<int NUM_UNROLL, int STEP = 0>
struct UnrollLoop {
    // Run the unrolled loop by recursively calling the operation
    template<typename Operation>
    static void run(Operation op) {
        op(STEP);  // Call the operation for the current step
        UnrollLoop<NUM_UNROLL, STEP + 1>::run(op);  // Recursive call for next step
    }
};

// Base case specialization to stop the unrolling when NUM_UNROLL equals STEP
template<int NUM_UNROLL>
struct UnrollLoop<NUM_UNROLL, NUM_UNROLL> {
    template<typename Operation>
    static void run(Operation) {
        // Do nothing - base case to stop recursion
    }
};

// Operation for the unroll loop demonstration
void printStep(int step) {
    std::cout << "Step: " << step << std::endl;
}

int main() {
    // Demonstrating factorial calculation
    constexpr int factorial5 = computeFactorial(5);
    std::cout << "Factorial of 5: " << factorial5 << std::endl;

    // Demonstrating log base 2 calculation
    constexpr int log2Of16 = LogBase2<16>::value;
    std::cout << "Log base 2 of 16: " << log2Of16 << std::endl;

    // Demonstrating logarithm of 100 with respect to base 10
    constexpr int log10Of100 = Logarithm<100, 10>::value;
    std::cout << "Log base 10 of 100: " << log10Of100 << std::endl;

    // Demonstrating loop unrolling for 5 iterations
    UnrollLoop<5>::run(printStep);

    return 0;
}
