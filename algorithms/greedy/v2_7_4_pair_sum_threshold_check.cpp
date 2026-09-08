#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >>k;

	for(int j=0;j<k;j++){
		cin >>n;
			int A[n];
			int B[n];
			for(int i=0;i<n;i++){
				cin >> A[i];
			}
			for(int i=0;i<n;i++){
				cin >> B[i];
			}
			sort(A,A+n);
			sort(B,B+n);
			int find;
			cin >> find;
			bool check=true;
			for(int i=0;i<n;i++){
				if(A[i]+A[n-i-1] < find){
					check=false;
					break;
				}
			}
			if(check){
				cout << "Yes"<<endl;
			}else{
				cout << "No"<<endl;
			}
	}
	
//		cin >> n >> k;
//	 A[n];
//	 B[k];
//	for(int i=0;i<n;i++){
//		cin >> A[i];
//	}
//	for(int i=0;i<n;i++){
//		cin >> B[i];
//	}
	
}
