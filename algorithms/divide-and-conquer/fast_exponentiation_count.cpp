#include <bits/stdc++.h>
using namespace std;

int counts = 0 ; 

int devide(int n, int k) {
    if (k == 0) {
        return 1;
    }
	
    if (k % 2 == 0) {
    	
        int half = devide(n, k / 2);  
        return half * half;
    } else {
    	counts++;
        int half = devide(n, (k - 1) / 2); 
        return n * half * half;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << devide(n, k) << " " ;
    cout << ++counts;
}

