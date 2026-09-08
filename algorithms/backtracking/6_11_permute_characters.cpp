#include <iostream>
using namespace std;
char C[27];
void rec(int A[], int left, int k, int right) {
    if (left == k) {
        for (int i = 1; i <= k; i++) {
            cout << C[A[i-1]]; 
        }
        cout << endl;
        return;
    } else {
        for (int i = 0; i < right; i++) {
            bool check = true;
            for (int j = 0; j < left; j++) {
                if (A[j] == i + 1) {
                    check = false;
                    break; 
                }
            }
            if (check) {
                A[left] = i + 1;
                rec(A, left + 1, k, right);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    C[n+1];
    for(int i=1;i<=n;i++){
    	cin >> C[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(int(C[i])<int(C[j])){
				swap(C[i],C[j]);
			}
		}
	}
    rec(A, 0, n, n);
    return 0;
}

