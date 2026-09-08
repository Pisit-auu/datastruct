#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    int left = 0, right = n - 1;
    int si = -1, sj = -1;
    int min_diff = INT_MAX;

    while (left < right) {
        int sum = A[left] + A[right];
        if (sum == k) {
            int diff = A[right] - A[left];
            if (diff < min_diff) {
                min_diff = diff;
                si = A[left];
                sj = A[right];
            }
            // Move both pointers to find other possible pairs
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    if (si != -1 && sj != -1) {
        cout << si << " " << sj << endl;
    } else {
        cout << "No such pair found" << endl;
    }

    return 0;
}
