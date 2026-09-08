#include <bits/stdc++.h>
using namespace std;
vector<int> memo(10000,-1);
int findsum(int A[],int find,int n){
	if(find==0){
		return 0;
	}
	if(n==0||find<0){
		return -1;
	}
	if(memo[n]!=-1){
		return memo[n];
	}
	int useAn = 1+findsum(A,find-A[n-1],n-1);
	int notAn = findsum(A,find,n-1);
	
	return memo[n] = max(useAn,notAn);
	
}

int main(){
	int n;
	
	cin >> n;
	int A[n+1];
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int find;
	cin >> find;
	cout << findsum(A,find,n-1);
	
}
