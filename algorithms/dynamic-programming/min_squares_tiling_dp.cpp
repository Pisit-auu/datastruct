#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int minSquaresDP(int w, int h) {
    vector<vector<int> > dp(w + 1, vector<int>(h + 1, 0));

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if (i == j) {
                dp[i][j] = 1; 
            } else {
                dp[i][j] = INT_MAX; 
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }

                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    return dp[w][h]; 
}

int main() {
    int w = 6, h = 7;
    cout << minSquaresDP(w, h) << endl;
    return 0;
}

