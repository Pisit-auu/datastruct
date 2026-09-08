#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Node;
	int p[] = {25,24,15,8};
	int w[] = {18,15,10,5};
	int n=4,m=25;
	int maxx = 0;

void prints(int A[],int n){
	int sumw = 0;
	for(int i=1;i<=n;i++){
		sumw += p[i-1]*A[i];
	}
	if(sumw>maxx){
		maxx = sumw;
		/*		for(int i=1;i<=n;i++){
					cout << A[i] << " ";
				}
				cout << endl;*/
	}
}
void subset(int A[],int r,int n,int sum){
	if(sum > m){
		return;
	}
	if(r==n){
		prints(A,n);
	}else{
		A[r+1] = 0;
		subset(A,r+1,n,sum);
		A[r+1] = 1;
		sum+= w[r];
		subset(A,r+1,n,sum);
		
	}
}
int main(){

	
	priority_queue<Node , vector<Node> , greater<Node> >  pq2;
	for(int i=0;i<n;i++){
		pq2.push({w[i],p[i]});
	}
	int i=0;
	while(!pq2.empty()){
		Node a = pq2.top();
		p[i] = a.second;
		w[i] = a.first;
		pq2.pop();
	}
	int x[4];
	int sum=0;
	subset(x,0,n,sum);
	cout << maxx <<endl;
	
}
