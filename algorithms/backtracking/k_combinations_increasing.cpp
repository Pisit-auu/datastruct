#include <bits/stdc++.h>
using namespace std;
vector<bool> used(1000,false);
int nub =0;
void p(int r,vector<int> A){
	for(int i=0;i<r;i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
void s(int n,int l,int r,vector<int> A){

	if(l==r){
		nub++;
		p(r,A);
		return;
	}
	for(int i=l+1;i<=n;i++){
		if(!used[i]){
			A[l] = i;
			if(A[l]<A[l-1]&&l>0){
				continue;
			}
			used[i] = true;
			s(n,l+1,r,A);
			used[i] = false;
		}
	}
	
}

int main(){
	int n;
	int m;
	cin >> n >>m;
	vector<int> A(m);
	s(n,0,m,A);
	cout << nub ;
}
