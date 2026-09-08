#include <bits/stdc++.h>
using namespace std;

int MaxCrossingProfit(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }

    return leftSum + rightSum;
}

int MaxProfit(vector<int>& arr, int low, int high) {
    if (low >= high) return 0; 

    int mid = (low + high) / 2;

    int leftProfit = MaxProfit(arr, low, mid);
    int rightProfit = MaxProfit(arr, mid + 1, high);
    int crossProfit = MaxCrossingProfit(arr, low, mid, high);
    int maxProfit = leftProfit;
    if (rightProfit > maxProfit) maxProfit = rightProfit;
    if (crossProfit > maxProfit) maxProfit = crossProfit;
	
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << MaxProfit(arr, 0, n - 1) << endl;
    return 0;
}
