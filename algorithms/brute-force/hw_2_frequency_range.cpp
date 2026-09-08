#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	cin >> n;
	int x;

	vector<int> temp(1000001,0);
	int max=0,min =1000001;
	int findmax =0;
	for(int i=0;i<n ;i++){
		cin >> x;
		temp[x]++;
		if(x>findmax ){
			findmax =x;
		}
	}
	for(int i=0;i<=findmax;i++){
		if(temp[i]>max){
			max = temp[i];	
		}
		if(temp[i]>0&& temp[i]<min){
			min = temp[i];
		}

	}
	cout << max - min ;
}
