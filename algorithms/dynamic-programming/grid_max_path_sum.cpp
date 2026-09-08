#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(10000,vector<int>(10000,-1));
int A[10000][10000];
int ant(int n,int k){
	if(n<0||k<0){
		return 0;
	}
	if(memo[n][k]!=-1){
		return memo[n][k];
	}
	int gox = A[n][k]+ ant(n-1,k);
	int goy = A[n][k]+ ant(n,k-1);
	return memo[n][k] = max(gox,goy);
}

int main(){
	int n,k;
	cin >> n >>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin >> A[i][j] ;
		}
	}
	cout << ant(n,k);
	
}
