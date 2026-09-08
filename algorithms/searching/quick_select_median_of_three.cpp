#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // ?????? rand()

using namespace std;
int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    // ???????????????????????
    if (arr[right] < arr[left])
        swap(arr[left], arr[right]);
    if (arr[mid] < arr[left])
        swap(arr[mid], arr[left]);
    if (arr[right] < arr[mid])
        swap(arr[right], arr[mid]);

    return mid; 
}
int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int quickselect(int arr[], int left, int right, int k) {
    if (left == right) { 
        return arr[left];
    }

    int pivotIndex = medianOfThree(arr, left, right);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

int main() {
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int k = 4; // ??????????????????????????? 3

    int result = quickselect(arr, 0, 9 - 1, k - 1); // ????????? index ??????????? 0
    cout << "min index " << k << " is " << result << endl;

    return 0;
}
