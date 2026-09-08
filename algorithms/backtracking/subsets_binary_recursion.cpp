#include <bits/stdc++.h>
using namespace std;
void print_sol(int x[],int n){
	
	for(int i=1;i<=n;i++){
		cout << x[i]<<" ";
	} 

	cout <<endl;
}
void subset1(int x[],int l,int r){
	if(l==r){
		print_sol(x,r);
	}else{
		x[l+1] = 0;
		subset1(x,l+1,r);
		x[l+1] = 1;
		subset1(x,l+1,r);
	}
}
int main(){
	int n=3;
	int x[n+1];
	subset1(x,0,n);
	return 0;
}
