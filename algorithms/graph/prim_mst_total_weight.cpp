#include <bits/stdc++.h>
using namespace std;
#define INF 50000

int V;
void prim(vector<pair<int, int> > adj[], int V, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, src});
    key[src] = 0;
        int mst_weight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        mst_weight += key[u];

        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].first;
            int weight = adj[u][j].second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    cout << mst_weight << endl;
}

typedef pair<int, int> node;

int main() {
    int n, m;
    cin >> n >> m;
    V = n;
    int u, v, w;
    vector<node> graph[n + 1];

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int src;
    cin >> src;
    prim(graph, V, src);
}

