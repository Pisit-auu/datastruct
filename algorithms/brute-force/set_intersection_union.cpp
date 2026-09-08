#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int main(){	
	int n;
	cin>>n;
	vector<int> A(n);
	vector<int> B(n);
	for(int i=0;i<n;i++){
		cin >> A[i];
	
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	vector<int> C(1000,0);
	vector<bool> checka(1000,true);
	vector<bool> checkb(1000,true);
	vector<int> intercept(n+n,0);
	vector<int> unionn(n+n,0);
	int countintercept =0;
	int countunion =0;
	for(int i=0;i<n;i++){
		if(checka[A[i]]){
		C[A[i]]++;	
		if(	C[A[i]]==1){
			unionn[countunion] = A[i];
			countunion++;
		}
		if(	C[A[i]]==2){
			intercept[countintercept] = A[i];
			countintercept++;
		}
		checka[A[i]]=false;	
		}
	}
	for(int i=0;i<n;i++){
				if(checkb[B[i]]){
		C[B[i]]++;	
		if(	C[B[i]]==1){
			unionn[countunion] = B[i];
			countunion++;
		}
		if(	C[B[i]]==2){
			intercept[countintercept] = B[i];
			countintercept++;
		}
		checkb[B[i]]=false;
		}
	}
	for(int i=0;i<countintercept ;i++){
			cout << intercept[i] <<" ";
	}
	cout <<endl;
		for(int i=0;i<countunion;i++){
			cout << unionn[i] <<" ";
	}
}
