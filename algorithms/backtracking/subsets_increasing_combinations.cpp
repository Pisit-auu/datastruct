#include <bits/stdc++.h>
using namespace std;


void print_subset(int x[],int l ){
	for(int i=1;i<=l;i++){
		cout << x[i]<< " ";
	}
	cout <<endl;
}
void subset2(int x[],int l,int n){
	print_subset(x,l);
	int j;
	if(l==0){
		j=1;
	} 
	else {
		j = x[l]+1;
	}
		for(int i=j;i<=n;i++){
			x[l+1] = i;
			subset2(x,l+1,n);
		}
}

int main(){
	int n=4;
	int x[n+1];
	subset2(x,0,n);
	return 0;
}
