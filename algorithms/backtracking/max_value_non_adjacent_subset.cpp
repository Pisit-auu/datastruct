#include <bits/stdc++.h>
using namespace std;
int maxx =0;
int C[10] = {30,10,8,20,11,12,25,13,20,19};
void p(int p,vector<int> A){
	int sum=0;
	for(int i=0;i<p;i++){
//		cout << A[i]<<" ";
		sum+=C[A[i]];
	}
	if(sum>maxx){
		maxx = sum;
	}
//	cout <<endl;
}
void sub(int l,int r,vector<int> A){
	p(l,A);
	int j;
	if(l==0){
		j=0;
	}else{
		j=A[l-1]+1;
	}
	for(int i=j;i<r;i++){
		A[l] = i;
		if(A[l]-A[l-1]==1){
			continue;
		}
		sub(l+1,r,A);
		
	}
}


int main(){
	int n=10;
	vector<int> A(n);
	sub(0,n,A);
	cout << maxx<<endl;
}
