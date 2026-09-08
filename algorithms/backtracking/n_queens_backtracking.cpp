#include <bits/stdc++.h>
using namespace std;
int n=4;
int x[4];
void nq(int k){
	if(k==n){
		for(int i=0;i<n;i++){
			cout << x[i] << " ";
		}
		cout << endl;
	}else{
		for(int row=0;row<n;row++){
			int flag=0;
			for(int p=0;p<k;p++){
				if(abs(p-k)==abs(x[p]-row)||(row==x[p])){
					flag=1;
					break;
				}
			}
					if(flag==0){
			x[k] =row;
			nq(k+1);
		}
		}

	}
	
}
int main(){
	nq(0);
}
