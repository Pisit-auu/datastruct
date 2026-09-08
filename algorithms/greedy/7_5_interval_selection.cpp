#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;

int main(){
	int n;
	cin >> n;
	priority_queue<Node , vector<Node> , greater<Node> >  pq2;
	vector<Node> keep;
	for(int i=0;i<n;i++){
		int n1,n2;
		cin >> n1 >>n2;
		pq2.push({n1,n2});
	}
	int i=-1;
	while(!pq2.empty()){
		Node a = pq2.top();
		cout << a.first <<" "<< a.second <<endl;
		int start = a.first ,end = a.second;
		if(keep.empty()){
			keep.push_back({start,end});
			i++;
		}else{
			if(keep[i].first !=start&& end >keep[i].second){
				keep.push_back({start,end});
				i++;
			}else if(keep[i].first==start && keep[i].second <end){
				keep[i] = {start,end};
			}
		}
		pq2.pop();
	}

	vector<Node> line;
	line.push_back(keep[0]);;
	
	int end = keep[0].second;
	for(int i=1;i<keep.size();i++){
		if(keep[i].first<end){
			line.back() = {keep[i].first,keep[i].second};
		}else {
			end =  keep[i].second;
			line.push_back({keep[i].first,keep[i].second});
		}
	}
	
		cout << line.size()+1<<endl;
		cout << keep[0].first <<" "<< keep[0].second <<endl;
		for(int i=0;i<line.size();i++){
		cout << line[i].first <<" "<< line[i].second <<endl;
		}
}
