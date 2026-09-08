#include <iostream>
using namespace std;
int count =0;
void rec(int A[], int left, int k, int right) {
    if (left == k) {
    	count++;
        for (int i = 0; i < k; i++) {
            cout << A[i] << " "; 
        }
        cout << endl;
        return;
    } else {
        for (int i = left; i < right; i++) {
            bool check = true;
            for (int j = 0; j < left; j++) {
                if (A[j] == i + 1 || A[j]> i+1) {
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
    int n, k;
    cin >> n >> k;
    int A[k];
    rec(A, 0, k, n);
    cout << count;
    return 0;
}

