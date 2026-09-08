#include <bits/stdc++.h>
using namespace std;
int A[] = {1,2,3,4,5,5,5,6,7,8};

int devide(int l,int r,int x){
	if(l>r){
		return 0;
	}
	int mid = (l+r)/2;
	if(A[mid]==x){
	
		return mid;
	}else if(A[mid]<x){
		return devide(mid+1, r, x);
	}else{
		return devide(l,mid, x);
	}
	
}
int main(){
	cout << devide(0,9,8);
}
