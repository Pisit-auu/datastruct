#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {  
        for (int j = i; j < n; j++) {  
            int sum = 0;
            for (int k = i; k <= j; k++) {  
                sum += A[k];
            }
            max_sum = max(max_sum, sum);  
        }
    }

    cout << max_sum ;
}

