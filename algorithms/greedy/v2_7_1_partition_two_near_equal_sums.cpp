#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;

	int sumall=0;
	cin >> n;
		int A[n];
	for(int i=0;i<n;i++){
		cin >> A[i];
		sumall+=A[i];
	}
	int average = (sumall/2)+1;
//	cout << "average : "<<average <<endl;
	sort(A,A+n,greater<int>());
	int suml=0,sumr=0;
	for(int i=0;i<n;i++){
        if (suml + A[i] <= average) { 
            suml += A[i];
        } else {
            sumr += A[i];
        }

		
	}
	cout << suml << endl;
	cout << sumr << endl;
	cout << abs(suml-sumr) ;
}
