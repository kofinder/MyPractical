#include <iostream>

struct Base {
    ~Base() { std::cout << "Base()" << std::endl; }
};

struct DerivedA : Base {
    ~DerivedA() { std::cout << "~DerivedA()\n"; }
};


struct VirtBase {
    virtual ~VirtBase() {
        std::cout << "~VirtBase()\n";
    }
};

struct DerivedB : VirtBase {
    ~DerivedB() {
        std::cout << "~DerivedB()\n";
    }
};

int main() {
    {
        Base base;
    }

    {
        DerivedA derivedA;
    }

    std::cout << "----\n";

    Base *pBase = new DerivedA;

    delete pBase; // bad

    VirtBase *pVirtBase = new DerivedB;
    delete pBase; // good
}

