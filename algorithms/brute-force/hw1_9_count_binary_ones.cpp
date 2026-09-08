#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int count=0;
	for(int i=n;i>0;i=i/2){
		if(i%2==1){
			count++;
		}
	}
	cout << count;
}
