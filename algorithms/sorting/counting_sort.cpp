#include <bits/stdc++.h>
using namespace std;
void sort(int A[],int max,int min,int n){
	vector<int> count(max-min+1,0);
	
	for(int i=0;i<n;i++){
		count[A[i]-min]++;
	}
	for(int j=1;j<= max-min;j++){
		count[j] =count[j-1]+count[j];
	}
	int S[n];
	for(int i=n-1;i>=0;i--){
		int j= A[i]-min;
		S[count[j]-1] =A[i];
		count[j] = count[j]-1;
	}
	for(int i=0;i<n;i++){
		A[i] = S[i];
		
	}
}
int main (){
	int A[] = {7,2,3,6,1,9,8,20};
	int n = 8;
	int max =0; int min =10000;
	for(int i=0 ;i<8;i++){
		if(A[i]>max){
			max = A[i];
		}
		if(A[i]<min){
			min = A[i];
		}
	}
	sort(A,max,min,n);
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
		
	}
}
