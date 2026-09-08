#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(100,vector<int>(100,-1));
vector<int > memo2(100,-1);

int F1(int n,int k){
	if(k==0||n==k||k==1){
		return 1;
	}
	if(memo[n][k]!=-1){
		return memo[n][k];
	}
	memo[n][k] = F1(n-1,k)+F1(n-1,k-2);
	return memo[n][k];
}
int F12(int n,int k){
	if(k==0||n==k||k==1){
		return 1;
	}
	if(memo[n][k]!=-1){
		return memo[n][k];
	}
	for(int i=0;i<=n;i++){
		for(int j=2;j<=k;j++){
			if(i!=j){
			  	memo[i][j] = F1(n-1,k)+F1(n-1,k-2);
			}
			
		}
	}

	return memo[n][k];
}
int F2(int n){
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		return 1;
	}
	for(int j=3;j<=n;j++){
		memo2[n] = F2(n-1)+F2(n-2)-F2(n-3);
	}
	
	return memo2[n];
}
int F22(int n){
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		return 1;
	}
	if(memo2[n] !=-1){
		return memo2[n];
		
	}
	memo2[n] = F2(n-1)+F2(n-2)-F2(n-3);
	return memo2[n];
}
int main(){
	cout << F1(5,4)<<endl;
	cout << F12(5,4)<<endl;
	cout << F2(7)<<endl;
	cout << F22(7)<<endl;
}
