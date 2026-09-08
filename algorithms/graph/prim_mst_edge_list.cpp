#include <bits/stdc++.h>
using namespace std;
#define INF 50000
typedef pair<int,int> node;
void dijkstra(vector<pair<int,int> > adj[],int V,int src){
	priority_queue< pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > pq;
	vector<int> dist(V,INF);
	vector<int> parent(V,-1);
	vector<bool> intree(V,false);
	pq.push({0,src});  
	dist[src] =0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		intree[u] = true;
		for(int j=0;j<adj[u].size();++j){
			int v = adj[u][j].first;
			int w = adj[u][j].second;
			if(intree[v] == false &&  w < dist[v]){
				dist[v] =  w;
				pq.push({dist[v], v}); 
				parent[v] = u;
			}
			
		}
	}
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " \t" << dist[i] << endl;
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
		
	
	
	for(int i=1;i<=n;i++){
		cout << "i" <<i<< ": ";
		for(int j=0;j<g[i].size();j++){
			cout << "("<<g[i][j].first <<","<< g[i][j].second << ") ";
		}
		cout << endl;
	}
	dijkstra(g,n+1,1);
}
