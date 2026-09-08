#include <iostream>
using namespace std;

void bubblesort(){
	
}

int main(){
	int A[] = {3,6,2,4,8,5};
	int n=6;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				swap(A[j],A[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
}
