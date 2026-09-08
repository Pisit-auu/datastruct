#include <bits/stdc++.h>
using namespace std;
void BFSparent(vector<int> g[],int src,int v){
	vector<int> parent(v,-1);
	queue<int> q;
	vector<bool> visited(v,false);
	q.push(src);
	visited[src] =true;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int i=0;i< g[a].size();i++){
			int neighbor = g[a][i];
			if(!visited[neighbor]){
				q.push(neighbor);
				visited[neighbor] = true;
				parent[neighbor] = a;
			}
		}
	}
	for(int i=0;i<=v;i++){
		cout << parent[i] <<" ";
	}
	cout << endl;
}
void BFS(vector<int> g[],int src,int v){
	
	queue<int> q;
	vector<bool> visited(v,false);
	q.push(src);
	visited[src] =true;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		cout << a <<" ";
		for(int i=0;i< g[a].size();i++){
			int neighbor = g[a][i];
			if(!visited[neighbor]){
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}
void DFS(vector<int> g[],int src,int v,vector<bool>& visited){
	cout << src <<" ";
	visited[src] = true;
	for(int i=0;i<g[src].size();i++){
		int neighbor = g[src][i];
		if(!visited[neighbor]){
			DFS(g,neighbor,v,visited);
		}
	}
}
bool cycleFoud = false;
void DFSfindcycle(vector<int> g[],int src,int v,vector<bool>& visited,vector<int>& parent){
	visited[src] = true;
	for(int i=0;i<g[src].size();i++){
		int neigth = g[src][i];
		if(!visited[neigth]){
			DFSfindcycle(g,neigth,v,visited,parent);
			parent[neigth] = src;
		}else if(parent[src]!= neigth ){
			cycleFoud =true;
			return;
		}
	}
}
int b(int V,vector<int> graph[]){
	vector<bool>visited (V,false);
	int group=0;
	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFS(graph,i,V,visited);
			group++;
		}
	}
	return group;
}
int main(){ 
	int v,e;
	cin>> v >> e;
	vector<int> graph[v+1];
	for(int i=0;i<e;i++){
		int start ;
		int end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	for(int i=0;i<=v;i++){
		cout << i <<": ";
		for(int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	BFS(graph,1,v);
	cout << endl;
	vector<bool> visit(v,false);
	DFS(graph,1,v,visit);
	cout << endl;
	BFSparent(graph,1,v);
	
	vector<bool> visit2(v,false);
	vector<int> parent(v,-1);
	DFSfindcycle(graph,1,v,visit2,parent);
	if(cycleFoud){
		cout << "s"<<endl;
	}
}
