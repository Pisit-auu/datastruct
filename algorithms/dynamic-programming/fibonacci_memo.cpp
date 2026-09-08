#include <bits/stdc++.h>
using namespace std;
vector<long long> memo(20,-1);
long long Fibo (int n){
	if(n<=0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	if(memo[n]!=-1){
		return memo[n];
	}
	memo[n]= Fibo(n-1)+Fibo(n-2);
	return memo[n];
}
int main(){
	cout << Fibo(6);
}
