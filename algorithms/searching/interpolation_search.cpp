#include <iostream>
using namespace std;
int interpolation(int A[],int l,int r,int p){
	if(l<=r){
		int x = l+(p-A[l])*(r-l)/(A[r]-A[l]);
		if(A[x]==p){
			return x;
		}else if(A[x]>p){
			return interpolation(A,l,x-1,p);
		}else {
			cout << r <<" ";
			return interpolation(A,x+1,r,p);
		}
	}
	
}

int main(){
	int A[] = {2,4,6,8,10};
	int n=5;
	int x = 6;
	int l=0,r=n-1;
	cout << interpolation(A,l,r,x);
}
