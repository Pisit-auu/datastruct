#include <bits/stdc++.h>
using namespace std;
int maxwalk ;
void DFS(vector<int> graph[], int startVertex, vector<bool>& visited,vector<int>& parent,int num) {
   // cout << startVertex<<" ";
   if(num ==maxwalk){
   	return;
   }
   	
    visited[startVertex] = true;
    for(int i=0;i < graph[startVertex].size();i++){
    	int check = graph[startVertex][i];
    	if( !visited[check]){
    		parent[check] = startVertex; 
    		DFS(graph,check,visited,parent,num+1);
		} 
	//	cout << endl;
	}
}
void find(vector<int> graph[], int n, int startVertex) {
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1, -1);
	DFS(graph, startVertex, visited,parent,0);
	int sum=0;
	for(int i=0;i< visited.size();i++){
		if(!visited[i]){
			sum++;
		}
	}
	cout << sum-1; 
}

int main() {
    int n;
    cin >> n;
    vector<int> graph[n+1];


        while(true){
        	int u;
        cin >> u;
            int v;
            cin >> v;
            if(u==0&&v==0){
            	break;
			}
            graph[u].push_back(v);
            graph[v].push_back(u);
            
		}
    
	int start;
	cin >>start >>maxwalk;


        find(graph,n,start);


    return 0;
}
