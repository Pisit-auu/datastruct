#include <iostream>
using namespace std;


int sum(int n){
	if(n==0){
		return 0;
	}else{
		return sum(n-1)+(n*n*n);
	}
}
int main(){
	int n=1000;
	cout << sum(n) <<endl;
}

