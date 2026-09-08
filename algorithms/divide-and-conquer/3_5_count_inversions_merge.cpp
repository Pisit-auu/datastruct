#include <bits/stdc++.h>
using namespace std;

int A[100000];
int q(int l,int mid ,int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int counts=0;
	int Al[n1];
	int Ar[n2];
	
	for(int i=0;i<n1;i++){
		Al[i] = A[l+i];
	}
	for(int i=0;i<n2;i++){
		Ar[i] = A[mid+i+1];
	}
	int i=0,j=0;
    while (i < n1 && j < n2) {
        if (Al[i] <= Ar[j]) {
            i++;
        }else {
            j++;
            counts += (n1 - i);  
        }
    }
	return counts;
}
int devide(int l,int r){
	int counts=0;
	if(l<r){
		int mid = (l+r)/2;
		counts += devide(l,mid);
		counts += devide(mid+1,r);
		counts += q(l,mid,r);
	}
	return counts;
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	cout <<devide(0,n-1);
}
