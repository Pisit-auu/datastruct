#include <iostream>
using namespace std;

int pivot(int A[],int l,int r){
	
	int mid = (l+r)/2;
    if (A[l] > A[mid]) swap(A[l], A[mid]);
    if (A[l] > A[r]) swap(A[l], A[r]);
    if (A[mid] > A[r]) swap(A[mid], A[r]);
	swap(A[mid],A[l]);
	return A[l];
}
int partition(int a[],int l,int r){
	int pivott,i,j,t;
	pivott = pivot(a,l,r);
	i = l;
	j = r;
	while(1){
		do{
			i++;
		}while(a[i]<= pivott);
		do{
			j--;
		}while(a[j]>pivott);
		
		if(i>=j){
			break;
		}
		swap(a[i],a[j]);
	}
	swap(a[l],a[j]);
	return j;
	
}
void quicksort(int A[],int l,int r){
	int p;
	if(l<r){
		p= partition(A,l,r);
		quicksort(A,l,p-1);
		quicksort(A,p+1,r);
	}
	
}
int main(){
		int A[] = {16,25,2,54,36,9,12,66};
		int n = 8; 
		quicksort(A,0,n-1);
		for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
	
}
