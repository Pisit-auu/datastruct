#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> DistributionCounting(int* A,int n,int l,int u){
	vector<int> S(n);
	vector<int> D(u - l + 1, 0);
	for(int j=0;j<=u-l;j++){
		D[j] =0;
	}
	for(int i=0;i<=n-1;i++){
			D[A[i]-l]= D[A[i]-l]+1;
		}
		
	for(int j=1;j<=u-l;j++){
		D[j] =D[j-1]+D[j];
	}
	for(int i=n-1;i>=0;i--){
			int j =A[i]-l;
			S[D[j]-1] = A[i];
			D[j] = D[j]-1;
		}
	return S;
}
int main(){
	int arr[] = {16,25,2,54,36,9,12,66};
	int n=8;
	int l = INT_MAX;
    int u = INT_MIN;
    for(int i=0;i<n;i++){
    	if(l>arr[i]){
    		l=arr[i];
		}
		if(u <arr[i]){
			u=arr[i];
		}
	}
	 vector<int> sorted =  DistributionCounting(arr,n,l,u);	
	for(int k=0;k<8;k++){
		cout << sorted[k] <<" ";
	}
	cout << endl;
}
