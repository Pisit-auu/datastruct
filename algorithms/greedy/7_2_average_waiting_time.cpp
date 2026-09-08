#include <bits/stdc++.h>
using namespace std;

float A[10000];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A,A+n);
	float sum=0;
	for( int i =1;i<=n;i++){
		for(int j=0;j<i;j++){
			sum+= A[j];
		}
	}
	printf("%.2f",sum/n);
	
}
