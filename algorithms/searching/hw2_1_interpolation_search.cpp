#include <iostream>
#include <vector>
using namespace std;

int InterSearch(const vector<int>& A,int k,int h,int l){
	int pos;
	pos = l + ((k-A[l])*(h-l))/(A[h]-A[l]);
	cout << pos <<" ";
	if(k==A[pos]){
		return pos;
	}else if(A[pos] < k){
		return InterSearch(A,k,h,pos+1);
	}else if(A[pos] > k){
		return InterSearch(A,k,pos-1,l);
	}
	
}
int main(){
	int n;
	int k;
	cin >> n;
	cin >> k;
	vector<int> A(n);
		int l=0;
	int h=n-1;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	InterSearch(A,k,h,l);
}
