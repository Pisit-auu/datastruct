#include <bits/stdc++.h>
using namespace std;
int C[100];
int minc=1000;
void p(int r,int A[]){
	int sumr=0;
	int suml=0;
	for(int i=0;i<r;i++){
		if(A[i]){
			sumr+=C[i];
		}else{
			suml+=C[i];
		}
	}
	if(abs(sumr-suml)<minc){
		minc = abs(sumr-suml);
	}
}
void subset(int l,int r,int A[]){
	if(l==r){
		p(r,A);
		return;
	}
	A[l]= 0;
	subset(l+1,r,A);
	A[l]= 1;
	subset(l+1,r,A);
}
int main(){
	int n;
	cin >>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin >> C[i];
	}
	subset(0,n,A);
	cout <<minc;
}
