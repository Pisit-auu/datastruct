#include <bits/stdc++.h>
using namespace std;

int coin_change(int w,int d[],int n){
	int cnts =0;
	for(int i=0;i<n;i++){
		cnts += w/d[i];
		w=w%d[i];
	}
	
	
	return cnts;
}
int main(){
	int d[] = {1,5,2,10};
		int n=4,W=6;
	sort(d, d + n, greater<int>());
	cout << coin_change(W,d,n) <<endl;
}
