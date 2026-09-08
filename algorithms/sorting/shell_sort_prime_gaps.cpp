#include <iostream>
using namespace std;
bool isPrime(int num) {

    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {  
        if (num % i == 0) return false;
    }
    return true;
}

int changeprime(int n) {
	if(n==0){
		return 0;
	}
    if (n <= 2) return 1;  
    int c = n;
    while (!isPrime(c)) { 
        c--;
    }
    return c;
}
int main(){
	int A[] = {16,25,2,54,36,9,12,66};
	int n = 8; 
	int i,j,k,temp;
	for( k= changeprime(n);k>0; k =changeprime(k-1)){
		for( i=k;i<n;i++){
			 temp = A[i];
			for( j=i;j>=k && A[j-k] > temp;j-=k){
				A[j] = A[j-k];
			}
			A[j] = temp;
		}
			for(int i=0;i<n;i++){
				cout << A[i] << " ";
			}
			cout <<endl;
		}
			for(int i=0;i<n;i++){
				cout << A[i] << " ";
			}

}
