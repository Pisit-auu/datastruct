#include <bits/stdc++.h>
using namespace std;
int as = 1;
int sqrt(int l,int r,int x){
	if(l>r){
		return r;
	}
	int mid = (l+r)/2;
	 if (mid * mid == x) {
        return mid;  
    } else if (mid * mid < x) {
    	as++;
        return sqrt(mid + 1, r, x); 
    } else {
    	as++;
        return sqrt(l, mid - 1, x);  
    }
	
}
int main(){
	int n;
	cin >> n;
	cout << sqrt(0,n,n)<<endl ;
	cout << as;
}
