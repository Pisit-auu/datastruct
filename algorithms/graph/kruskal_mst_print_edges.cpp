#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void union1(vector<int>& parent, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int is_cycle(vector<int>& parent, int u, int v) {
    int x = find(parent, u);
    int y = find(parent, v);
    return (x == y) ? true : false;
}

void kruskal(vector<pair<int, int> > adj[], int n) {
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }


    for (int u = 1; u <= n; ++u) {
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            pq.push({w, {u, v}});
        }
    }

    int ne = 0;
    while (ne < n - 1) {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();

        if (!is_cycle(parent, u, v)) {
            ne++;
            union1(parent, u, v);
            cout << "(" << u << "," << v << "," << w << ")" << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int> > g[n + 1];
    int u, v, w;

    // รับข้อมูลขอบและน้ำหนัก
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // แสดงกราฟ adjacency list
    for (int i = 1; i <= n; i++) {
        cout << "i" << i << ": ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << "(" << g[i][j].first << "," << g[i][j].second << ") ";
        }
        cout << endl;
    }

    // คำนวณ MST โดยใช้ Kruskal
    kruskal(g, n);
}

