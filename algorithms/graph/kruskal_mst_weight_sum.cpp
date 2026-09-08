#include <bits/stdc++.h>
using namespace std;
int sumtong =0;

int find(vector<int>& parent,int i){
	if(parent[i]==i){
		return i;
	}
	return find(parent,parent[i]);
}
void union1(vector<int>& parent,int x,int y){
	int xroot = find(parent,x);
	int yroot = find(parent,y);
	parent[xroot] = yroot;
}
bool is_cycle(vector<int>& parent, int u,int v){
	int x= find(parent,u);
	int y = find(parent,v);
	return(x==y)? true:false;
}
void kruskal(vector<pair<int, int> > adj[],int V){
	   priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > pq;

	vector<int> parent(V);
	for(int i=0;i<V;++i){
		parent[i] = i;
	}
	 for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            pq.push({adj[i][j].second, {i, adj[i][j].first}});
        }
    }
	int ne =0;
	while(ne<V-1 && !pq.empty()){
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w  = pq.top().first;
		pq.pop();
		if(!is_cycle(parent,u,v)){
			ne++;
			union1(parent,u,v);
			sumtong+= (w-1);
		}
	}
}

int main(){
		int n,m;
	cin >> n>>m;
	vector<pair<int,int> > g[n+1];
		int u,v,w;
	for(int i=0;i<m;i++){
		cin >> u >> v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
			
	}
	kruskal(g,n+1);
	cout << sumtong;
}
