#include <iostream>
#include <cmath>
using namespace std;
void merge(int* A,int l,int r,int mid){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int larr[n1];
	int rarr[n2];
	for(int i=0;i<n1;i++){
		larr[i] = A[l+i];
	}
	for(int i=0;i<n2;i++){
		rarr[i] = A[mid+1+i];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(larr[i]<=rarr[j]){
			A[k] = larr[i];
			i++;
		}else{
			A[k] = rarr[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k] = larr[i];
		k++;i++;
	}
	while(j<n2){
		A[k] = rarr[j];
		k++;j++;
	}
}
void mergesort(int* A,int l,int r){
	if(l<r){
		int mid = l+(r-l)/2;
		mergesort(A,l,mid);
		mergesort(A,mid+1,r);
		merge(A,l,r,mid);
	}
}





int searchm(int* A,int m,int l,int r){
	if(l==r){
		return l;
	}
		int mid = (l+r)/2;
		if(m<A[mid]){
			 return searchm(A, m, l, mid); 
		}else{
			 return searchm(A,m,mid+1,r);
		}
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int k;
	int m;
	cin >> m;
	cin >>  k;
	mergesort(A,0,n-1);
	int index= searchm(A,m,0,n);
	int left = index-1;
	int right =index;
	while (right-left <= k){
		cout << left << " ";
		cout << right << endl;
		if( abs(A[left]-m) > abs(A[right]-m)){
			right +=1;
		}else{
			left-=1;
		}
	};
}

