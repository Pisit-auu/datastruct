#include <iostream>
using namespace std;
void mergesort(int A[] , int l,int mid ,int r){
	int n1= mid-l+1;
	int n2 =  r-mid;
	int Al[n1];
	int Ar[n2];
	for(int i=0;i<n1;i++){
		Al[i] = A[l+i];
	}
	for(int i=0;i<n2;i++){
		Ar[i] = A[mid+i+1];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(Al[i]<Ar[j]){
			A[k] = Al[i];
			i++;
		}else{
			A[k] = Ar[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k] = Al[i];
		i++;
		k++;
	}
	while(j<n2){
		A[k] = Ar[j];
		j++;
		k++;
	}
	
}
void merge(int A[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		merge(A,l,mid);
		merge(A,mid+1,r);
		mergesort(A,l,mid,r);
	}
}
int main(){
	int A[] = {16,25,2,54,36,9,12,66};
	int n = 8; 
	merge(A,0,n-1);
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
}
