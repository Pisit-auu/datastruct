#include <bits/stdc++.h>
using namespace std;
int countcoins =0;
int A[100000];
void print_sol(int x[],int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+= x[i]*A[i-1];
	} 
	if(sum>countcoins){
		countcoins=sum;
	}

}
void subset1(int x[],int l,int r){
	if(l==r){
		print_sol(x,r);
	}else{
		x[l+1] = 0;
		subset1(x,l+1,r);
		if(x[l]==1){
			return;
		}
		x[l+1] = 1;
		subset1(x,l+1,r);
	}
}
int main(){
	int n;
	cin >>n;
	n++;
	A[n];
	for(int i=0;i<n-1;i++){
		cin >> A[i];
	}
	int x[n+1];
	subset1(x,0,n);
	cout << countcoins;
	return 0;
}
