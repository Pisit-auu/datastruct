#include <iostream>
using namespace std;
bool isPrime(int num){
	if(num<2) return false;
	for(int i=2;i*i<=num;i++){
		if(num%i==0)return false;
	}
	return  true;
}
int changeprime(int n){
	if(n==0){
		return 0;
	}
	if(n<2)return 1;
	int c=n;
	while(!isPrime(c)){
		c--;
	}
	return c;
}
int main(){
	int n;
	cin >> n;
	int A[n];
	
	for(int i=0;i<n;i++){
		cin>> A[i];
	}
	int k,i,j,temp;
	for(i =changeprime(n);i>0;i=changeprime(i-1)){
		for(j=i;j<n;j++){
			temp = A[j];
			for(k=j ; k>=i && A[k-i]>temp; k-=i){
				A[k] = A[k-i];
			}
			A[k] =temp;
		}
			for(int l=0;l<n;l++){
				cout << A[l] <<" ";
				
			}
			cout<<endl;
	}
}

