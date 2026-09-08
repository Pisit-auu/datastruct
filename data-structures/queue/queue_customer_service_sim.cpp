#include <iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	int a[n];
	int s[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> s[i];
	}
	int tempa;
	int temps;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				tempa = a[i];
				temps = s[i];
				a[i] = a[j];
				s[i] = s[j];
				a[j] = tempa;
				s[j] = temps;
			}
		}
	}
	int t=a[0];
	for(int i=0;i<n;i++){
		cout << a[i] <<" "<< s[i]+a[i]<<endl;
		a[i+1] = s[i]+a[i];
	}
	
}
