#include <iostream>
using namespace std;

bool check(int A[], int n, int i = 0){
	if(i==n-1){
		return true;
	}
	if(A[i]>A[i+1]){
		return false;
	}
	return check(A,n,i+1);
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for( int i=0;i<n;i++){
		cin >> A[i];
	}
	cout << (check(A,n)?"Yes":"No");
}
