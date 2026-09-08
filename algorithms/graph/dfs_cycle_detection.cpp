#include <bits/stdc++.h>
using namespace std;
bool cycleFound =false;
void DFS(vector<int> graph[], int startVertex, vector<bool>& visited,vector<int>& parent) {
   // cout << startVertex<<" ";
    visited[startVertex] = true;
    for(int i=0;i < graph[startVertex].size();i++){
    	int check = graph[startVertex][i];
    	
    	if( !visited[check]){
    		parent[check] = startVertex; 
    		DFS(graph,check,visited,parent);
		}else if(check != parent[startVertex]){
			cycleFound= true;
			return;
		}
	//	cout << endl;
	}
}
void find(vector<int> graph[], int n, int startVertex) {
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1, -1);
	DFS(graph, startVertex, visited,parent);
}

int main() {
    int n;
    cin >> n;
    vector<int> graph[n+1];

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        while (true) {
            int v;
            cin >> v;
            if (v == 0) {
                break;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
	


    for (int i = 0; i < n; i++) {
        find(graph,n,i);
    }
    if(cycleFound){
    	cout << 1;
	}else{
		cout << 0;
	}

    return 0;
}

