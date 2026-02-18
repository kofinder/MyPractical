struct B0 {

    public:

        virtual int f() const = 0;

        virtual ~B0() = default;
};


struct B1 {

    public:

        virtual int g() const = 0;

        virtual ~B1() = default;
};

struct D0 : public B0 {

    public:
    
        int f() const override { return 1; }
};


struct D1 : public B1 {

    public:
        int g() const override { return 2; }
};


struct D: public D0, public D1 {};


int f(D* p) {
    return p ? p->f() + p->g() : -1;
}


int g(D0* d) {
    auto dcast = dynamic_cast<D1&>(*d);
    return dcast.g(); // throws error if wrong
}



#include <iostream>

int main() {

    D d;
    f(&d);
    g(&d);

    D0 d0;

    try {
        g(&d0);
    } catch(const std::bad_cast& e) {
        std::cerr << "Nice Try" << '\n';
    }
    
    return 0;
}