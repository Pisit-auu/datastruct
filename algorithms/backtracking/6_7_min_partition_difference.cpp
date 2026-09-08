#include <iostream>
#include <cmath>
using namespace std;
int x[150][2];
int minn=301;
void recreverse(int B[], int left, int right,int suma) {
    if (left == right) {
    	int sumb=0;
        for (int i = 0; i < right; i++) {
           // cout << A[i] << " "; 
            sumb+= x[i][B[i]-1];
           
        }
      //  cout << "suma = " << suma <<endl;
        // cout << "sumb = " << sumb <<endl;
         // cout << "sumb-sumb = " << abs(suma-sumb) <<endl;
        //  cout << "minn " << minn<<endl;
           if(suma-sumb==0){
           	return;
		   }
        if(abs(suma-sumb) < minn){
        	minn = abs(suma-sumb);
		}
        //cout << endl;
         //cout << endl;
        return;
    } else {
        for (int i = 2; i >0; i--) {
                B[left] = i;
                recreverse(B, left+1, right,suma);
        }
    }
}
void rec(int A[], int left, int right) {
    if (left == right) {
    	int sum=0;
        for (int i = 0; i < right; i++) {
             sum+= x[i][A[i]-1];
        }
        int B[right];
        recreverse(B, 0, 4,sum);
        return;
    } else {
        for (int i = 0; i < 2; i++) {
                A[left] = i + 1;
                rec(A, left + 1, right);
        }
    }
}

int main() {
	int n;
	cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
    	cin>> x[i][0]>>x[i][1];
	}
	rec(A, 0, n) ;
    cout <<minn ;
    return 0;
}

