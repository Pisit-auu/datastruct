#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(1000,vector<int>(1000,-1));
int A[1000][1000];
int ant(int n,int m){
	if(n<0||m<0){
		return 0;
	}
	if(memo[n][m]!=-1){
		return memo[n][m];
	}
	int gox = A[n][m]+ ant(n-1,m);
	int goy = A[n][m]+ ant(n,m-1);
	memo[n][m] = max(gox,goy);
	return memo[n][m];
}
int main(){
	int n;
	cin >>n;
	int m;
	cin >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> A[i][j];
		}
	}
	cout <<  ant(n-1,m-1);
}
