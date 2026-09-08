#include <bits/stdc++.h>
using namespace std;
	int countrec=0;


int main(){

	 
	 int m,n;
	 cin >> m;
	 cin >> n;
	 while(m!=0&&n!=0){
	 	if(m<n){
	 		n-=m;
	 		countrec++;
		 }else{
		 	m-=n;
		 	countrec++;
		 }
	 }
	cout << countrec;

}
