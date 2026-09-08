#include <bits/stdc++.h>
using namespace std;
int A[4]= {1,2,3,4};
vector<bool> used(3,false);
void printp(vector<int> B,int r){
	for(int i=0;i<r;i++){
		cout << B[i] << ' ';
	}
	cout <<endl;
}
void permutation(vector<int>& B,int l,int r){
	if(l > 0 && B[l-1] == 3&& B[l]==1){
		return;
	}
	if(l+1 < r && B[l+1] == 3&& B[l]==1){
		return;
	}
	if(l==r){
		printp(B,r);
		return;
	}
	for(int i=0;i<r;i++){
		if(!used[i]){
			B[l] = A[i];
			used[i] = true;
			permutation(B,l+1,r);
			used[i]=false;
		}
	}
}
int main(){
	vector<int> B(4);
	int n=4;
	permutation(B,0,n);
}
