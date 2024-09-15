#include <vector>

void getMinAndMax(int numbers[], int size, int* min, int* max) {
    for(int i = 0; i < size; i++) {
        if(numbers[i] < *min) {
            *min = numbers[i];
        }
        if(numbers[i] > *max) {
            *max = numbers[i];
        }
    }
}

bool ascendingCompare(int a, int b) {
    return a < b;
}

bool descendingCompare(int a, int b) {
    return a > b;
}
