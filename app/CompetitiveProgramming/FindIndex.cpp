#include <iostream>

int findIndex(int items[], int size, int item) {
    for(int i = 0; i < size; i++) {
        if(items[i] == item) return i;
    }

    return -1;
}

int main() {
    
    int items[] = {1, 5, -3, 10, 55, 100};
    int size = sizeof(items) / sizeof(items[0]);  // total elements

    int idx = findIndex(items, size, 10);

    using namespace std;
    cout << "Result Idex of donate Number ===>:" << idx << endl;

    return 0;
}