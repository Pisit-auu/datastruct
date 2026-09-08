#include <iostream>
using namespace std;

int main(){
	int A[] = {2,1,5,7,3,9,4};
	int n = 7; 
	int i,j,v;
	for( i=1;i<n;i++){
		j=i-1;
		v = A[i];
		while(j>=0&&A[j]>v){
			A[j+1]= A[j];
			j--;
		}
		A[j+1] = v;
	}
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
}
