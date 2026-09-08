#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > memo(1000,vector<long long> (1000,-1));
int A[5] ={1,2,3,4,5};
long long dnmc4(int n,int m){
	if(n==m){
		return A[n];
	}
	if(m==0){
		return 0;
	}
	if(n>m){
		return 0;
	}
	if(memo[n][m]!=-1){
		return memo[n][m];
	}
	memo[n][m] = max(dnmc4(n+1,m),dnmc4(n,m-1))+ A[m];
	return memo[n][m];
}
int main(){
	cout << dnmc4(1,4);
}
