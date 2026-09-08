#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(1000,vector<int>(1000,-1));
int cnk(int n,int k){
	if(k==0|| n==k){
		return 1;
	}
	if(memo[n][k]!=-1){
		memo[n][k];
	}
	memo[n][k] = cnk(n-1,k-1) + cnk(n-1,k);
	return memo[n][k];
}

int main(){
	int n,k;
	cin >> n >>k;
	cout << cnk(n,k);
}
