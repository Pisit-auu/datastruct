#include <bits/stdc++.h>
using namespace std;
// -1 is a real answer ("no subset reaches the target"), so the memo needs a
// separate marker for "not calculated yet".
const int NOT_CALCULATED = -2;
vector<vector<int> > memo;

int findsum(int A[],int find,int n){
	if(find==0){
		return 0;
	}
	if(n==0||find<0){
		return -1;
	}
	// the answer depends on both n and the remaining target, so memo is indexed by both
	if(memo[n][find]!=NOT_CALCULATED){
		return memo[n][find];
	}
	int useAn = findsum(A,find-A[n-1],n-1);
	if(useAn!=-1){
		useAn = useAn+1;
	}
	int notAn = findsum(A,find,n-1);

	return memo[n][find] = max(useAn,notAn);

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
	memo.assign(n+1,vector<int>(find+1,NOT_CALCULATED));
	cout << findsum(A,find,n);

}
