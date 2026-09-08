#include<bits/stdc++.h>
using namespace std;
vector<double> memo(50,-1);
int A[1000];
double findMean(int n){
	if(n==0){
		return 0;
	}
	if(memo[n]!=-1){
		return memo[n];
	}
	memo[n] = (A[n]+(n-1)*findMean(n-1))/n;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> A[i] ;
	}
	printf("%.2f",findMean(n));
}
