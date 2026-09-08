#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(100,vector<int>(100,-1));

int tiger(int n,int m){
	if(n==0||m==0){
		return 0;
	}
	if(n==1||m==1){
		memo[n][m]=1;
		return memo[n][m];
	}
	if(memo[n][m]!=-1){
		return memo[n][m];
	}
	memo[n][m] = tiger(n-1,m)+tiger(n,m-1);
	return memo[n][m];
}

int main(){
	cout << tiger(2,5);	
	cout <<endl;
	for(int i=0;i<=5;i++){
		for(int j=0;j<=5;j++){
			cout <<	memo[i][j]<<" ";
		}
		cout <<endl;
	}
}
