#include <bits/stdc++.h>
using namespace std;
vector<bool> used(1000,false);
void p(int r,vector<int> A,vector<char> C){
	for(int i=0;i<r;i++){
		cout << C[A[i]-1] <<" ";
	}
	cout <<endl;
}
void permute(int l,int r,vector<int> A,vector<char> C){
	
	if(l==r){
		p(r,A,C);
		return;
	}
	for(int i=0;i<r;i++){
		if(!used[i]){
			A[l] = i+1;
		used[i] = true;
		permute(l+1,r,A,C);
		used[i] = false;
		}
		
		
	}
	
}
int main(){
	int n;
	cin >> n;
	vector<int> A(n);
	vector<char> c(n);
	for(int i=0;i<n;i++){
		cin >> c[i] ;
	}
	sort(c.begin(),c.end());
	permute(0,n,A,c);
}
