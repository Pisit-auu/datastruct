#include <bits/stdc++.h>
using namespace std;
int minn=1000,keepV=0;
void BFS(vector<vector<int> > &graph, int startVertex, int V) {
    vector<bool> visited(V+1, false);
    vector<int> parent(V+1, -1);
    queue<int> queue;
    
    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
      //cout << currentVertex << " ";
        for (int i = 1; i <= V; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {  
                queue.push(i);
                visited[i] = true;
                parent[i] = currentVertex;
            }
        }
    }
     int sum=0;
     

	vector<bool> visitedcheck(V+1, false);
     for(int i=1;i<parent.size();i++){
     	if(parent[i]!=-1){
     		if(!visitedcheck[parent[i]]){
     			visitedcheck[parent[i]]= true;
     			sum++;
			 }
		 }
	 }
	 if(sum<minn){
	 	minn = sum;
	 	keepV= startVertex;
	 }
}
void printg(vector<vector<int> > graph,int n){
	for(int i=1;i< graph.size();i++){
		cout << i << ": ";
		for(int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
int main() {
    int n,m;
    cin >> n>>m;
    vector<vector<int> > graph(n + 1, vector<int>(m+ 1, 0));

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        int v;
        cin >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;  
    }
    for(int i=1;i<=n;i++){
    	BFS(graph,i,m);
	}
	
	cout << keepV;
    return 0;
}

