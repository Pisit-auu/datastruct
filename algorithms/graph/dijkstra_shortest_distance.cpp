#include <bits/stdc++.h>
using namespace std;
#define INF 50000
void dijkstra(vector<pair<int,int> > adj[],int V,int src,int find){
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
			if(intree[v] == false && dist[u] + w < dist[v]){
				dist[v] = dist[u]+ w;
				pq.push({dist[v], v});
				parent[v] = u;
			}
			
		}
	}
    int search = find; 
    if (dist[search] == INF) {
        cout << "No path to node " << search << endl;
    } else {
    vector<int> path;
        for (int v = search; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        
        cout <<  dist[search];
        cout << endl;
    }
}
int main(){
	int round;
	cin >> round;
	for(int i=0;i<round;i++){
			int n,m;
			cin >> n>>m;
			int src,find;
			cin >> src>>find;
			vector<pair<int,int> > g[n+1];
			int u,v,w;
			for(int i=0;i<m;i++){
				cin >> u >> v>>w;
				g[u].push_back({v,w});
				g[v].push_back({u,w});
					
			}
				dijkstra(g,n,src,find);
	}
}
