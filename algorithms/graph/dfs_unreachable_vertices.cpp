#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], int startVertex, vector<bool>& visited) {
   // cout << startVertex<<" ";
    visited[startVertex] = true;
    for(int i=0;i < graph[startVertex].size();i++){
    	int check = graph[startVertex][i];
    	if( !visited[check]){
    		DFS(graph,check,visited);
		}
	//	cout << endl;
	}
}
void printg(vector<int> graph[],int n){
	for(int i=0;i<n;i++){
		cout << i << ": ";
		for(int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
void find(vector<int> graph[], int n, int startVertex) {
	vector<bool> visited(n + 1, false);
	DFS(graph, startVertex, visited);
	vector<int> checkdontgo;
	 for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            checkdontgo.push_back(i);
        }
    }
    if (checkdontgo.empty()) {
        cout << "0";
    } else {
        for (size_t i = 0; i < checkdontgo.size(); i++) {
            if (i > 0) cout << " ";
            cout << checkdontgo[i];
        }
    }
    cout << endl;
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
        }
    }
	
    int nstartVertex;
    
  	cin >> nstartVertex ;


    for (int i = 0; i < nstartVertex; i++) {
        int startVertex;
        cin >> startVertex;
        find(graph,n,startVertex);
    }

    return 0;
}

