#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> money;

int main(){
	int n;
	cin >> n;
	priority_queue<money , vector<money> , greater<money> >  pq2;
	for(int i=0;i<n;i++){
		int n1,n2;
		cin >> n1 >>n2;
		pq2.push({n1,n2});
	}
	int suml =0,sumr=0;
	while(!pq2.empty()){
		money a = pq2.top();
		if(suml==sumr){
			suml+= a.first;
			sumr+= a.second;
		}else if(suml>sumr){
			if(a.first>a.second){
				suml+= a.second;
				sumr+= a.first;
			}else{
				suml+= a.first;
				sumr+= a.second;
			}
		}else{
			if(a.first>a.second){
				suml+= a.first;
				sumr+= a.second;
			}else{
				suml+= a.second;
				sumr+= a.first;
			}
		}
		//cout << suml <<" "<< sumr <<endl;
		pq2.pop();
	}
	cout << abs(suml-sumr) <<endl;
}
