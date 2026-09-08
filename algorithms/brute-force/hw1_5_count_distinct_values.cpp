#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	cin >> n;
	int x;
	vector<int> temp(100001,0);
	int max=0;
	for(int i=0;i<n;i++){
		cin >> x;
		if(x>max){
			max =x;
		}
		temp[x]++;
	}
	int count=0;
	for(int i=0;i<=max;i++){
		if(temp[i]>0)count++;
	}
	cout << count;
}
