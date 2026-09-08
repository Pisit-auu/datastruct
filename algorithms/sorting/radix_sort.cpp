#include <bits/stdc++.h>
using namespace std;

void radixSort(int A[], int n) {
    vector<int> asort;
    int maxVal = *max_element(A, A + n);
    int exp = 1;

    while (maxVal / exp > 0) { 
        vector<int> temp[10]; // ??? vector ??? array 2 ????

        // ????????????????????? (digit buckets)
        for (int i = 0; i < n; i++) {
            int digit = (A[i] / exp) % 10;
            temp[digit].push_back(A[i]);
        }

        // ???????????????????? `A`
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : temp[i]) {
                A[index++] = num;
            }
        }

        exp *= 10; // ??????????????????
    }
}

int main() {
    int A[] = {22, 61, 51, 17, 13, 29, 4};
    int n = sizeof(A) / sizeof(A[0]);

    radixSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

