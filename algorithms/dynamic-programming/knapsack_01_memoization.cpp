#include <bits/stdc++.h>
using namespace std;
vector <vector<int> > memo(1000,vector<int>(1000,-1));
int v[1000];
int w[1000];
int back(int n,int capacity){
	if(n==0|| capacity==0){
		return 0;
	}
	if(capacity < w[n-1]){
		return memo[n][capacity] = back(n - 1, capacity);
	}

	if(memo[n][capacity]!=-1){
		return memo[n][capacity];
	}
	int choose = v[n-1]+back(n-1,capacity-w[n-1]);
	int nochoose = back(n-1,capacity);
	memo[n][capacity] = max(nochoose,choose);
	return memo[n][capacity];
}
int main(){
	int n;
	int capacity;
	cin >> n >> capacity;
	for(int i=0;i<n;i++){
		cin >> w[i];
	}
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	cout << back(n,capacity)<<cout;
	for(int i=0;i<n;i++){
		for(int j=0;j<=capacity;j++){
			cout << memo[i][j]<<" ";
		}
		cout << endl;
	}
} 
