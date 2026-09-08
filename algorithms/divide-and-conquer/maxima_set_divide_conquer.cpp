#include <bits/stdc++.h>
using namespace std;
int A[100000][2] ;
vector<int> status(100000,1);
void mergesort(int l,int mid,int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int Al[n1][2];
	int Ar[n2][2];
	for(int i=0;i<n1;i++){
	   Al[i][0] = A[i+l][0];
	   Al[i][1] = A[i+l][1];
	}
	for(int i=0;i<n2;i++){
		Ar[i][0] = A[mid+i+1][0];
		Ar[i][1] = A[mid+i+1][1];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(Al[i][0]<Ar[j][0]){
			A[k][0] = Al[i][0];
			A[k][1] = Al[i][1];
			i++;
		}else{
			A[k][0]= Ar[j][0];
			A[k][1]= Ar[j][1];
			j++;
		}
		k++;
	}
	while(i<n1){
			A[k][0] = Al[i][0];
			A[k][1] = Al[i][1];
		i++;k++;
	}
	while(j<n2){
			A[k][0]= Ar[j][0];
			A[k][1]= Ar[j][1];
		j++;k++;
	}
	
}
void conq(int l,int m,int r){
	int k;
	for(int i=m+1;i<r;i++){
		if(status[i]==1){
			k=i;
			break;
		}
	}
	for(int i=l;i<=m;i++){
		if(status[i]==1&&A[i][1]<A[k][1]){
			status[i]=0;
		}
	}
}
void maxima(int l,int r){
	if(l<r){
		int mid = l+(r-l)/2;
		maxima(l,mid);
		maxima(mid+1,r);
		conq(l,mid,r);
	}
}
void merge(int l,int r){
	if(l<r){
		int mid = l+(r-l)/2;
		merge(l,mid);
		merge(mid+1,r);
		mergesort(l,mid,r);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		
		cin >> A[i][0] >> A[i][1];
	}
	merge(0,n-1);
	maxima(0,n-1);
	for(int i=0;i<n;i++){
		if(status[i]==1){
			cout << A[i][0]<<","  << A[i][1] <<" ";
		}
	}
	return 0;
}
