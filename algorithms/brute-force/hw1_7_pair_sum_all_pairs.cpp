#include <iostream>
using namespace std;

int main(){
	int n;
	int x;
	
	cin >>  n;
	cin >> x;
	int A[n];
	for(int i=0;i<n;i++){
		cin >> A[i] ;
	}
	for(int i=0;i<n;i++){
		for( int j=i+1;j<n;j++){
			if(A[i]+A[j]==x){
				cout << A[i] <<" "<<A[j]<<" "<< endl;
			}
		}
	}
}
