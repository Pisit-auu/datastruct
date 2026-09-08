#include <bits/stdc++.h>
using namespace std;
int A[501];

int par(int l,int r){
	int mid = l+(r-l)/2;
	if(A[l]>A[mid]){
		swap(A[l],A[mid]);
	}
		if(A[l]>A[r]){
		swap(A[l],A[r]);
	}
	if(A[mid]>A[r]){
		swap(A[mid],A[r]);
	}
	int p = A[mid];
	swap(A[mid],A[r]);
	int i=l-1; int j=r;
	do{
		do{
			i++;
		}while(A[i]<p);
		do{
			j--;
		}while(A[j]>p);
		swap(A[i],A[j]);
		
	}while(i<j);
	swap(A[i],A[j]);
	swap(A[r],A[i]);
	cout << i+1 <<" ";
	return i;
}
void quicksort(int l,int r){
	if(l<r){
		int p = par(l,r);
		quicksort(l,p-1);
		quicksort(p+1,r);
	}
}


int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	quicksort(0, n-1);
	cout <<endl;
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
}
