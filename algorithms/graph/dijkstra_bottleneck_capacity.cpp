#include <bits/stdc++.h>
using namespace std;
#define INF 50000
typedef pair<int,int> node;
int people ,endt ,start;
int ming = 50000;
int maxx =1;
void dijkstra(vector<pair<int,int> > adj[],int V,int src,int end){
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
		ming = 50000;
		for(int j=0;j<adj[u].size();++j){
			int v = adj[u][j].first;
			int w = adj[u][j].second;
			if((intree[v] == false &&  w < dist[v] && (people+1)/w < ming) || V==end){
				
				if(people/w> maxx){
					maxx = (people+1)/w;
				}
				ming = (people+1)/w;
				dist[v] =  w;
				pq.push({dist[v], v}); 
				parent[v] = u;
			}
			
		}
		 
	}
//    cout << "Edge \tWeight\n";
//    for (int i = 1; i < V; i++) {
//        if (parent[i] != -1) {
//            cout << parent[i] << " - " << i << " \t" << dist[i] << endl;
//        }
//}
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
	cin >> start >> endt >> people;
	dijkstra(g,n+1,start,endt);
	cout << maxx;
}
