#include <bits/stdc++.h>
using namespace std;
int counttime=0;
void print_sol(int x[],int n){
	int print=0;
	bool checkstart=true;
	
	for(int i=n;i>0;i--){
		print++;
		if(x[i]){
			cout<<print;
			checkstart=false;
		}
	} 
	if(checkstart){
		cout<<0;
	}
	cout <<endl;
}
void subset1(int x[],int l,int r){
	if(l==r){
		counttime++;
		print_sol(x,r);
	}else{
		x[l+1] = 0;
		subset1(x,l+1,r);
		x[l+1] = 1;
		subset1(x,l+1,r);
	}
}
int main(){
	int n;
	cin >> n;
	int x[n+1];
	subset1(x,0,n);
	cout << counttime;
	return 0;
}

