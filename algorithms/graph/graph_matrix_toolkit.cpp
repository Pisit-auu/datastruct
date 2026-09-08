#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int> > &graph,int start,int n,vector<bool>& visit){
	cout << start<<" ";
	visit[start] = true;
	for(int i=1;i<=n;i++){
		if(graph[start][i] == 1 && !visit[i]){
				DFS(graph,i,n,visit);
		}
	}
	
}
void BFS(vector<vector<int> > &graph,int start,int n){
	vector<bool> visit(n+1,false);
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while(!q.empty()){
		int curent = q.front();
		q.pop();
		cout << curent << " ";  
		for(int i=1;i<graph.size();i++){
			if(graph[curent][i] == 1 && !visit[i]){
				q.push(i);
				visit[i] =true;
				
			}
		}
	}
	cout << endl;
	
}
void printgraph(vector<vector<int> >& graph,int n){
		for(int i=1;i<=n;i++){
			for(int j=1;j< graph[i].size();j++){
				cout << graph[i][j] << " ";
			}
			cout <<endl;
		}	
}
void warshall(vector<vector<int> >& graph,int n){
	int R[n+1][n+1];
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			R[i][j] = graph[i][j];
		}
	}
	for(k=1;k<n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
			}
		}
	}
		    for (int i = 1; i <= n; i++) { // Start from 0, not 1
		        for (int j = 1; j <= n; j++) { // Use correct loop condition
		            cout << R[i][j] << " ";
		        }
		        cout << endl;
		    }

	
	
}
void shortest(vector<vector<int> > &graph, int start, int n) {
    vector<bool> visit(n + 1, false);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[current][i] == 1 && !visit[i]) {
                q.push(i);
                visit[i] = true;
                parent[i] = current;
            }
        }
    }
   	int find=1; int sum=0;
   	
	while(parent[find] != -1){
		find = parent[find];
		sum++;
	}
	cout << sum;
}
void BFSparent(vector<vector<int> > &graph,int start,int n){
	vector<bool> visit(n+1,false);
	vector<int> parent(n+1,-1);
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while(!q.empty()){
		int curent = q.front();
		q.pop();
		for(int i=1;i<graph.size();i++){
			if(graph[curent][i] == 1 && !visit[i]){
				q.push(i);
				visit[i] =true;
				parent[i] = curent;
				
			}
		}
	}
	int find; int sum=0;
	for(int i=1;i<=n;i++){
		cout << parent[i]<< " ";
	}
}
int Connected(int V,vector<vector<int> > &graph){
	vector<bool> visited(V,false);
	int group =0;
	for(int i=1;i<=V;i++){
		if(!visited[i]){
			DFS(graph,i,V,visited);
			group++;
		}
	}
	cout <<endl;
	return group;
	
}
bool cycleFound =false;

void DFSloop(vector<vector<int> > &graph,int start,int n,vector<bool>& visit,vector<int>& parent){
	visit[start] = true;
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			parent[i]= start;
			DFSloop(graph,i,n,visit,parent);
		}else if(parent[start] != i && parent[start] != -1){
			cycleFound =true;
			return;
		}
	}
	
}
int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		int u,v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printgraph(graph,n);
	cout << "BFS start at :";
	BFS(graph,1,n);
	
	vector<bool> visit(n+1,false);
	cout << "DFS start at :";
	DFS(graph,1,n,visit);
	cout << endl;
	BFSparent(graph,3,n);
	cout << "\nBFS find length 1 to 3 : ";
	shortest(graph,3,n);
	cout << endl;
	warshall(graph,n);
	cout << endl;
	cout << Connected(n,graph)<< endl;
	vector<bool> visit2(n+1,false);
	vector<int> parent(n+1,-1);
	DFSloop(graph,1,n,visit2,parent);
	if(cycleFound){
		cout <<1<<endl;
	}else{
		cout <<0<<endl;
	}
	
	
	
}
