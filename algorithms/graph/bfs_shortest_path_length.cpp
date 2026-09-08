#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > &graph, int startVertex, int V,int end) {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> queue;
    
    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
      //  cout << currentVertex << " ";

        for (int i = 1; i < V; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {  // Check edge existence and unvisited
                queue.push(i);
                visited[i] = true;
                parent[i] = currentVertex;
            }
        }
    }
    //cout <<endl;
    int find = end;
    int counttime=0;
    while(parent[find] != -1){
    	find = parent[find];
    	counttime++;
	}
	cout << counttime;
}
void printg(vector<vector<int> > graph,int n){
	for(int i=0;i< graph.size();i++){
		cout << i << ": ";
		for(int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        while (true) {
            int v;
            cin >> v;
            if (v == 0) {
                break;
            }
            graph[u][v] = 1;
            graph[v][u] = 1;  // Since it's an undirected graph
        }
    }

    int startVertex,end;
    cin >> startVertex>>end;
    BFS(graph, startVertex, n + 1,end);
	//printg(graph,n);
    return 0;
}

