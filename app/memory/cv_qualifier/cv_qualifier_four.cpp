

#include <bit>

struct A { int a; double b; };

struct B { unsigned int c; double d; };

int main() {

    constexpr A a{ 3, 3.5 }; // Nice, a simple struct

    constexpr B b = std::bit_cast<B>(a); // Whoa! Bit casting at compile time

    static_assert(a.a == b.c && a.b == b.d); // OMG, it actually works perfectly!

    static_assert((void*)&a != (void*)&b); // Mind blown: a and b are separate objects

    return 0;
}
