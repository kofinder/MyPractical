#include <iostream>

using namespace std;


/*
   This program illustrates the usage of virtual for abstract, interface, and pure function.
 */
class Instrument {
    public:
        virtual void makeSound() = 0; // pure virtual function
};


class Accordion: public Instrument {
    public:
        void makeSound() {
            cout << "Accordion is Playing ...." << endl;
        }

};

class Piano: public Instrument {
    public:
        void makeSound() {
            cout << "Piano is Playing ...." << endl;
        }
};