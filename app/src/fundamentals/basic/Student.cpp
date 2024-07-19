#include <iostream>

using namespace std;

/*
   This program illustrates the usage of constructors for copying, destroying and firend class.
 */
class Student {
    private:
        string name;
        int age;
        string address;

    public:
        Student() {
            cout << "Default Constructor" << endl;
        }

        Student(string _name, int _age, string _address) {
            cout << "Override Constructor" << endl;
            name = _name;
            age = _age;
            address = _address;
        }

        Student(const Student& original) {
            cout << "Copy Constructor" << endl;
            name = original.name;
            age = original.age;
            address = original.address;
        }
        
        // Destructor
        ~Student() {
            cout << "Destory Constructor" << endl;
        }

        void getInfo() {
            cout << "NAME =====>:" << name << endl;
            cout << "AGE ======>:" << age << endl;
            cout << "ADDRESS ==>:" << address << endl;
        }

        friend void printResults(Student);

        friend class Teacher;  
};


class Teacher {
    public:
        void PrintResults(Student student) {
            cout << "name ==>" << student.name << endl;
            cout << "age ==>" << student.age << endl;
            cout << "address ==>" << student.address << endl;
        }

};


void printResults(Student student) {
    cout << "name ==>" << student.name << endl;
    cout << "age ==>" << student.age << endl;
    cout << "address ==>" << student.address << endl;
}