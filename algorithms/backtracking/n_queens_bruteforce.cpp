#include <iostream>
#include <cmath>
using namespace std;

int n=4,x[4];
int coutns=0;

void n_queens(int k){
	if(k==n){
		int flag =0;
		for(int j=1;j<k;j++){
			for(int p=0;p<j;p++){
				if(abs(p-j)==abs(x[p]-x[j])||(x[j]==x[p])){
					flag=1;
				}
			}
		}
		if(flag==0){
			coutns++;
			for(int i=0;i<k;i++){
				cout << x[i]+1<<" ";
			}
			cout << endl;
		}
	}else{
		for(int row =0;row<n;row++){
			x[k] = row;
			n_queens(k+1);
		}
	}
}
int main(){
	n_queens(0);
	cout << coutns;
	return 0;
}
