#include <bits/stdc++.h>
using namespace std;
int A[100000];



int main(){
	int n,k;
	cin >>n >>k;
	int max=0,min=1000;
	
	for(int i=0;i<n;i++){
		cin >>A[i];
		if(A[i]>max){
			max =A[i];
		}
		if(A[i]<min){
			min = A[i];
		}
	}
	vector<int> D(max-min+1,0);
	for(int i=0;i<=n-1;i++){
		D[A[i]-min] ++;
	}
	for(int j=1;j<=max-min;j++){
		D[j] = D[j-1]+D[j];
	}
	int S[n];
	for(int i=n-1;i>=0;i--){
		int j= A[i]-min;
		S[D[j]-1]=A[i];
	}
	cout << S[k-1] << " " << k ;

}
