#include <bits/stdc++.h>
using namespace std;
vector<long long> memo(10000,-1);
long long fractorail(int n){
	if(n==0){
		return 1;
	}
	if(memo[n]!=-1){
		return memo[n];
	}
	memo[n] = n*fractorail(n-1);
	return memo[n];
}

int main(){
	cout << fractorail(10);
}
