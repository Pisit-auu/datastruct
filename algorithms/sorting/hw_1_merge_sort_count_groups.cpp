#include <iostream>
#include <cmath>
using namespace std;
void mergesort(int* A,int l, int mid,int r){
	int n1= mid-l+1;
	int n2= r-mid;
	int arrL[n1];
	int arrR[n2];
	for(int i=0;i<n1;i++){
		arrL[i] = A[l+i];
	}
	for(int i=0;i<n2;i++){
		arrR[i] = A[mid+1+i];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(arrL[i]<=arrR[j]){
			A[k] = arrL[i];
			i++;
		}else{
			A[k] = arrR[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k] = arrL[i];
		k++;
		i++;
	}
	while(j<n2){
		A[k] = arrR[j];
		k++;
		j++;
	}
}

void merge(int* A,int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		 merge(A,l,mid);
		merge(A,mid+1,r);
		mergesort(A,l,mid,r);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>> arr[i];
	}
	merge(arr,0,n-1);
	int count =1;
	for(int i=0;i<n-1;i++){
		if(abs(arr[i]-arr[i+1])>1){
			count++;
		}
	}
	cout << count;
}
