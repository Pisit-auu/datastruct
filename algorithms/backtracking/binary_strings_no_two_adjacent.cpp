#include <bits/stdc++.h>
using namespace std;
int A[1000];
void printx(int r){
	for(int i=0;i<r;i++){
		cout << A[i]<<" ";
	}
	cout << endl;
}
void binary(int l,int r){
	if(l==r){
		printx(r);
		return;
	}
	A[l]=0;

	binary(l+1,r);
	A[l]=1;
	if(l>0&&A[l-1]==1){
		return;
	}
	binary(l+1,r);
}
int main(){
	int n;
	cin >> n;
	binary(0,n);
}
