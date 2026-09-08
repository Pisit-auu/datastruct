#include <bits/stdc++.h>
using namespace std;
int A[900000];

int devide(int l,int r,int k){
	 if (l > r) return 0;
	if(l==r){
		if(A[r]==k){
			return 1;
		}else{
			return 0;
		}
	}else{
		int st1 = l + (r - l) / 3;
   		 int st2 = l + 2 * (r - l) / 3;
		return devide(l,st1,k)+devide(st1+1,st2,k)+devide(st2+1,r,k);
	}
	
	
}
int main(){
	int n,k;
	cin >> n>>k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int result = devide(0,n-1,k);
	if(result ==0){
		result = -1;
	}
	cout << result ;
	
}
