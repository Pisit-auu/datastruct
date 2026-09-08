#include <bits/stdc++.h>
using namespace std;
#include <cmath>
int check=0;
bool checkprime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}
void swap(int *a,int *b){
	swap(*a,*b);
}

void permute(int x[],int start,int end){
	if(start==end){
		for(int i=1;i<=end;i++){
		//	cout << x[i] << " ";
			if(!checkprime(x[i]+x[i+1])){
				return;
			}
		}
		check++;
		for(int i=1;i<=end;i++){
			cout << x[i] << " ";
		}
		cout << x[end+1];
		cout <<endl;
		return;
	}
	for(int i=start;i<=end;i++){
		swap(x[start],x[i]);
		permute(x,start+1,end);
		swap(x[start],x[i]);
	}
}

int main(){
	int n;
	cin>>n;
	int x[n+1];
	x[0] = -1;
	for(int i=1;i<n+1;i++){
		x[i] = i;
	}
	permute(x,1,n-1);
	cout <<check ;

}

