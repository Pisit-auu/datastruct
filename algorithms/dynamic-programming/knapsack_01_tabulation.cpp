#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (j < w[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }
    
    cout << dp[n][capacity] << endl;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
