#include <bits/stdc++.h>
using namespace std;
typedef pair<float,pair<float,pair<float,int> > > Node2;

float v[10000];
float w[10000];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> w[i];	
	}
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	priority_queue<Node2 , vector<Node2> >  pq3;
	
	for(int i=0;i<n;i++){
		pq3.push({v[i]/w[i] ,{v[i] ,{w[i],i}}});
	}
	float sumv=0,sumw=0;
	float keepuse[n]={0};
	while(!pq3.empty()){
		Node2 a = pq3.top();
		cout << a.first<< " " << a.second.first <<" " << a.second.second.first <<endl;
		if(sumw+a.second.second.first<=k){
			sumw += a.second.second.first;
			keepuse[a.second.second.second] = 1;
			sumv += a.second.first;
		}else{
			float temp = k-sumw;
			sumv+= a.first*temp;
			keepuse[a.second.second.second] = a.first/temp;
			sumw += temp;
			break;
		}
		pq3.pop();

	}
	for(int i=0;i<n;i++){
		printf("%.2f ",keepuse[i]);
	}
	printf("\n%.2f", sumv);
	
	
}
