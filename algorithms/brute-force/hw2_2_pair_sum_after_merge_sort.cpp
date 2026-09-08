#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
void merge(vector<int>& arr,int left,int mid,int right){
	int n1 = mid-left+1;
	int n2 = right-mid;
	vector<int> leftArr(n1), rightArr(n2);
	
	for(int i=0;i<n1;i++){
		leftArr[i] = arr[left+i];
	}
	for(int i=0;i<n2;i++){
		rightArr[i] = arr[mid+1+i];
	}
	int i=0,j=0,k=left;
	while(i<n1&&j<n2){
		if(leftArr[i]<=rightArr[j]){
			arr[k] =  leftArr[i];
			i++;
		}else{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
		
	}
	while (i<n1){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}
void MergeSort(vector<int>& arr,int left,int right){
	if(left < right){
		int mid = left+(right-left)/2;
		
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main(){
	int n,k;
	cin >> n;
	cin >> k;
	int sum = INT_MAX;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	MergeSort(A,0,n-1);

	int L=0,R=n-1;
	for(int i=0;i<n;i++){
		if(A[L]+A[R]>k){
			R-=1;
		}else if(A[L]+A[R]<k){
			L+=1;
		}else{
			if(abs(A[L]-A[R])<sum){
				sum = abs(A[L]-A[R]);
				L++;
			}
		}
		
	}
	
	cout << sum;
}
