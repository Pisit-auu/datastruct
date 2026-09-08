#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> memo(1000, -1);

int horse(int k) {
    if(k == 0) return 1;  
    if(k < 0) return 0;   
    if(memo[k] != -1) return memo[k]; 

    memo[k] = 0;
    for(int i = 1; i <= m; i++) {
        memo[k] += horse(k - i);
    }

    return memo[k];
}

int main() {
    cin >> n >> m;
    cout << horse(n) << endl; 
}

