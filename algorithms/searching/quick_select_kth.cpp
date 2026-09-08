#include<stdio.h>

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4; 
int n = sizeof(arr) / sizeof(arr[0]);
int partition(int arr[], int l, int r) {
    int middle = (l + r) / 2;
    if (arr[middle] < arr[l]) {
        int temp = arr[middle];
        arr[middle] = arr[l];
        arr[l] = temp;
    }
    if (arr[r] < arr[l]) {
        int temp = arr[r];
        arr[r] = arr[l];
        arr[l] = temp;
    }
    if (arr[middle] < arr[r]) {
        int temp = arr[middle];
        arr[middle] = arr[r];
        arr[r] = temp;
    }
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];
    int p = partition(arr, low, high);
    if (p == k) 
        return arr[p];
    else if (k < p) 
        return quickSelect(arr, low, p - 1, k);
    else { 
        return quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    printf("%d", quickSelect(arr, 0, n - 1, k));
    return 0;
}

