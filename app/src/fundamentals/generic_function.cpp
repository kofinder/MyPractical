#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void swap(int a, int b) {
    a = a+b -(b=a);
}

template<typename T>
void swap(T& a, T& b) {
    a = a + b;
    b = a - b;
    a = a -b;
}

template<typename S>
void swap(S* a, S* b){
    S t;
    t = *b;
    *b = *a;
    *a = t;
}

void pointerTypeCast(void *ptr, char type) {
    switch (type) {
        case 'i':
            cout << *(int *)ptr << endl;
            break;
        case 'c':
            cout << *(char *)ptr << endl;
            break;
        case 's':
            cout << *(string *)ptr << endl;
            break;
        default:
            cout << "undefined type" << endl;
            break;
    }
}

int main() {
    {
        unique_ptr<int> uniPtr1 = make_unique<int>(70);
        unique_ptr<int> uniPtr2 = move(uniPtr1); // pointer one memory allocation will be automatically deallocated
        // cout << "Unique ponter1 ====>: " << *uniPtr1 << endl; // Can causing error
        cout << "Unique ponter2 ====>: " << *uniPtr2 << endl;
    }

    {
        shared_ptr<int> sharPtr = make_shared<int>(30);
        shared_ptr<int> sharPtr2 = sharPtr;
        cout << "Shared ponter1 count ====>: " << sharPtr.use_count() << endl;
        cout << "Shared ponter2 count ====>: " << sharPtr2.use_count() << endl;

    }

    {
        weak_ptr<int> weakPtr;
        shared_ptr<int> sharedPtr3 = make_shared<int>(60);
        weakPtr = sharedPtr3;
        cout << "Weak count ====>: " << weakPtr.use_count() << endl;
    }
    return 0;
}
