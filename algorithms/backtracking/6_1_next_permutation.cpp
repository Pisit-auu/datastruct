#include <bits/stdc++.h>
using namespace std;

bool next_permutation_custom(vector<char>& arr) {
    int n = arr.size();
    
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) return false;

    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    swap(arr[i], arr[j]);

    reverse(arr.begin() + i + 1, arr.end());

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    do {
        for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
        cout << endl;
    } while (next_permutation_custom(arr));
}

