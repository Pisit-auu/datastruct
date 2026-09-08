#include <iostream>
using namespace std;

int main(){
	int A[] = {2,1,5,7,3,9,4};
	int n = 7;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[i]<A[j]){
				swap(A[i],A[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
}
