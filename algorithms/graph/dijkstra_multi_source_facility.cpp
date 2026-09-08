#include <bits/stdc++.h>
using namespace std;
#define INF 50000
int maxx =0;
int newHospital=0;
vector<int> hospitals; 
void dijkstra(vector<pair<int, int> > adj[], int V, int src, vector<int>& globalDist) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(V, INF);
    vector<bool> intree(V, false);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        intree[u] = true;

        for (size_t j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;

            if (!intree[v] &&  dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] < globalDist[i]) {
            globalDist[i] = dist[i];
        }
    }
}
int main(){
	
	int f,n;
	cin >> f>>n;
	for(int i=0;i<f;i++){
		int start;
		cin >> start;
		hospitals.push_back(start);
		}
	vector<pair<int,int> > g[n+1];
		int u,v,w;
		for(int i=0;i<n;i++){
			cin >> u >> v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
				
		}
		 vector<int> globalDist(n + 1, INF);

    for (size_t i = 0; i < hospitals.size(); i++) {
        dijkstra(g, n + 1, hospitals[i], globalDist);
    }


    for (int i = 0; i < n + 1; i++) {
        if (globalDist[i] > maxx && globalDist[i] != INF) {
            maxx = globalDist[i];
            newHospital = i;
        }
    }
	
    cout << newHospital << endl;  

}
