#include <iostream>
#include <vector>
using namespace std;

int InterSearch(const vector<int>& A,int k,int h,int l){
	// without these guards a missing key recurses forever and indexes out of range
	if(l>h || k<A[l] || k>A[h]){
		return -1;
	}
	if(A[h]==A[l]){
		// flat range, no interpolation possible without dividing by zero
		return (A[l]==k) ? l : -1;
	}
	int pos;
	pos = l + ((k-A[l])*(h-l))/(A[h]-A[l]);
	cout << pos <<" ";
	if(k==A[pos]){
		return pos;
	}else if(A[pos] < k){
		return InterSearch(A,k,h,pos+1);
	}else{
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
	int pos = InterSearch(A,k,h,l);
	cout << endl << pos;
}
