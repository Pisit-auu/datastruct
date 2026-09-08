#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int count=0;
 	for(int i=0;i<n;i+=2){
 		cout << A[i]<<" " << A[i+1]<<endl;
 		if(A[i]>A[i+1]){
 			count+=A[i]; 
		 }else{
		 	count+=A[i+1];
		 	i=i+1;
		 }
	 }
	
	cout << count;
}
