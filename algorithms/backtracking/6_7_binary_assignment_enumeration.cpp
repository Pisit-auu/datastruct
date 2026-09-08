#include <iostream>
using namespace std;
int count =0;
void recreverse(int A[], int left, int right) {
    if (left == right) {
    	count++;
        for (int i = 0; i < right; i++) {
            cout << A[i] << " "; 
        }
        cout << endl;
        return;
    } else {
        for (int i = 2; i >0; i--) {
                A[left] = i;
                recreverse(A, left+1, right);
        }
    }
}
void rec(int A[], int left, int right) {
	
    if (left == right) {
    //	cout << endl;
    	count++;
        for (int i = 0; i < right; i++) {
            cout << A[i] << " "; 
        }
        cout << endl;
       // cout << endl;
       // recreverse(A, 0, 4);
        return;
    } else {
        for (int i = 0; i < 2; i++) {
                A[left] = i + 1;
                rec(A, left + 1, right);
        }
    }
}


int main() {

    int A[4];
	rec(A, 0, 4) ;
    cout << endl;
    //recreverse(A, 0, 4);
    return 0;
}

