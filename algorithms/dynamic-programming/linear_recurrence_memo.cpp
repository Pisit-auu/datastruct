#include<bits/stdc++.h>
using namespace std;
vector<int> memo(50,-1);
int sum(int n){
	if(n==1||n==2){
		return 1;
	}
	if(memo[n]!=-1){
		return memo[n];
	}
	memo[n] = 3*sum(n-1)+sum(n-2);
	return memo[n];
}

int main(){
	int n;
	cin >> n;
	cout << sum(n) ;
}
