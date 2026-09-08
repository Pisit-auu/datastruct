#include <iostream>
using namespace std;

int arr[] = {16,-25,2,-54,36,9,-12,66};
int max(int l,int r){
	return (l>r)?l:r;
}
int Max_Subarry_Sum(int* A,int n){
	if(n==1){
		return A[0];
	}
	int m = n/2;
	int Lmss = Max_Subarry_Sum(A,m);
	int Rmss = Max_Subarry_Sum(A+m,n-m);
	int lsum = -1000,rsum = -1000,sum = 0;
		cout << "Lmss = "<< Lmss << " Rmss ="  << Rmss <<endl;
		cout << "m = " << m << " " <<"n = "<< n <<endl;
	for(int i = m;i<n;i++){
		sum+= A[i];
		rsum = max(rsum,sum);
	}
	cout << "rsum = " <<  rsum << ": sum "<< sum <<endl;
	sum = 0;
	for(int i=m-1;i>=0;i--){
		
		sum+= A[i];
		lsum = max(lsum,sum);
		
	}
	cout << "lsum = " <<  lsum << ": sum "<< sum <<endl;
	cout << "return " << max(max(Lmss,Rmss ),lsum+rsum)<<endl <<endl;
	return max(max(Lmss,Rmss ),lsum+rsum);
}
int main(){
	cout << Max_Subarry_Sum(arr,8);
}
