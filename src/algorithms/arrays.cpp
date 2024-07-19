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



// void customSort(vector<int>& numbers, bool(*compareFnPtr)(int, int)) {
//     for(int startIdx = 0; startIdx < numbers.size(); startIdx++) {
//         int bestIndex = startIdx;
//                 for(int currentIdx = startIdx + 1; currentIdx < numbers.size(); currentIdx++) {
//             if(compareFnPtr(numbers[currentIdx], numbers[bestIndex])) {
//                 bestIndex = currentIdx;
//             }
//         }
//         swap(numbers[startIdx], numbers[bestIndex]);
//     }
// }

// void printArrays(vector<int> numbers) {
//     for(int i = 0; i < numbers.size(); i++) {
//         cout << numbers[i] << endl;
//     }
// }

