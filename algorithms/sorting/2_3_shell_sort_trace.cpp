#include <iostream>
using namespace std;
#include <climits>

int main(){
	int n=8;
	int A[] = {16,25,2,54,36,9,12,66};
	int size = (n%2==0)? (n-1):n;
	int temp,i,j,k,count=1;
	cout<< count <<": ";
		for(int x=0;x<n;x++){
			cout << A[x] <<" ";
		}
		cout<<"\n";
		count+=1;
	for(i=size-2;i>0;i=i-2){
		cout<<"k = " << i <<endl;
		for(j=i;j<size;j++){
			temp=A[j];
			for(k=j;k>=i&&A[k-i]>temp;k-=i){
				A[k]= A[k-i];
			}
			A[k]=temp;
				cout<< count <<": ";
			for(int x=0;x<n;x++){
				cout << A[x] <<" ";
			}
				cout<<"\n";
				count+=1;
		}
	}
	
	
}
