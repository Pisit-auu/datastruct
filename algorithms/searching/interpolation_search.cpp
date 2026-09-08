#include <iostream>
using namespace std;
int interpolation(int A[],int l,int r,int p){
	// keep p inside [A[l],A[r]] so the interpolated index stays in range
	if(l<=r && p>=A[l] && p<=A[r]){
		if(A[l]==A[r]){
			// flat range, no interpolation possible without dividing by zero
			return (A[l]==p) ? l : -1;
		}
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
	return -1;
}

int main(){
	int A[] = {2,4,6,8,10};
	int n=5;
	int x = 6;
	int l=0,r=n-1;
	cout << interpolation(A,l,r,x);
}
