#include <iostream>
using namespace std;


int sum(int A[],int n){
	if(n==0){
		return A[n];
	}else{
		return sum(A,n-1)+A[n-1];
	}
}
int main(){
	int A[] = {5,6,8,2,1};
	int n=5;
	
	cout << sum(A,n) <<endl;
}

