#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;
typedef pair<int,pair<int,int> > Node2;
int main(){
	vector<Node> v1;
	v1.push_back({1,2});
	v1.push_back({4,5});
	v1.push_back({0,3});
	cout << v1[0].first<<" " << v1[0].second  <<endl;
		cout << v1[1].first<<" " << v1[1].second  <<endl;
			cout << v1[2].first<<" " << v1[2].second  <<endl;
	//            inside  ,stuct, sort defalt = max->min
	priority_queue<int ,vector<int>,greater<int> > pq;  //min heap
	pq.push(9);
	pq.push(3);
	while(!pq.empty()){
		int a = pq.top();
	//	cout << a<< " ";
		pq.pop();
	}
	cout << endl;
	priority_queue<Node , vector<Node> , greater<Node> >  pq2;
	pq2.push({3,6});
	
	pq2.push({9,10});
	pq2.push({0,5});

	priority_queue<Node2 , vector<Node2> >  pq3;
	while(!pq2.empty()){
		Node a = pq2.top();
		pq3.push({a.second-a.first ,{a.first,a.second}});
		//	cout << a.first<< " " << a.second <<endl;
		pq2.pop();
	}
	while(!pq3.empty()){
		Node2 a = pq3.top();
		cout << a.first<< " " << a.second.first <<" " << a.second.second <<endl;
		
		pq3.pop();
	}
	return 0;
}
