#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to search for the index of M in sorted array A
int searchIndex(const vector<int>& A, int M) {
    auto it = lower_bound(A.begin(), A.end(), M); // Use binary search to find the position
    if (it == A.end()) return A.size() - 1;      // If not found, return the last index
    int index = it - A.begin();                  // Calculate index
    if (index > 0 && abs(A[index - 1] - M) <= abs(A[index] - M))
        return index - 1;                        // Return the closer index if needed
    return index;
}

// Function to find k nearest items to M
void searchNearest(const vector<int>& A, int M, int k) {
    vector<int> sortedA = A;                     // Make a copy of the array to sort
    sort(sortedA.begin(), sortedA.end());        // Step 1: Sort A in ascending order
    
    int i = searchIndex(sortedA, M);             // Step 2: Search for the index of M
    int left = i - 1, right = i;                 // Step 3: Initialize left and right pointers

    cout << "The " << k << " nearest items to " << M << " are: ";
    while ((right - left - 1) < k) {             // Step 4: Find k nearest items
        if (left < 0) {                          // If left pointer is out of bounds
            right++;
        } else if (right >= sortedA.size()) {    // If right pointer is out of bounds
            left--;
        } else if (abs(sortedA[left] - M) <= abs(sortedA[right] - M)) {
            left--;                              // Expand the range by moving left pointer
        } else {
            right++;                             // Expand the range by moving right pointer
        }
    }

    for (int j = left + 1; j < right; j++) {     // Step 5: Print the nearest items
        cout << sortedA[j] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> A = {10, 20, 30, 40, 50};
    int M = 35; // Target number
    int k = 3;  // Number of nearest items to find

    searchNearest(A, M, k);

    return 0;
}

