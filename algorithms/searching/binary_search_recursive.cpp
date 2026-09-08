#include <iostream>
using namespace std;

int binarysearch(int A[],int l,int r,int find){
	if(l<r){
		int mid = (l+r)/2;
		if(A[mid] ==find ){
			return mid;
		}
		else if(A[mid] > find){
			return binarysearch(A,l,mid-1,find);
		}else if(A[mid] < find){
			return binarysearch(A,mid+1,r,find);
		}
	}
}

int main(){
	int A[] = {1,2,4,5,6,7,8,9};
	int l=0;
	int r = 8-1;
	int x = 9;
	cout << binarysearch(A,l,r,x);
}
