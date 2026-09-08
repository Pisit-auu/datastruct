#include <bits/stdc++.h>
using namespace std;
#define TRUE 1
#define FALSE -1
#define inf 50000

int mindistance(int dist[],int intree[],int v){
	int min = inf;
	int min_index = -1;

	for(int i=1;i<v;i++){
		if(intree[i] ==FALSE && dist[i] <= min){
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}
void dijkstra(vector<vector<int> > g,int v,int src){
	int dist[v];
	int intree[v];
	int parent[v];
	for(int i=0;i<v;i++){
		dist[i] = inf;
		parent[i] = -1;
		intree[i] = -1;
	}
	dist[src]= 0;
	for(int i=1;i<v;i++){
		int u = mindistance(dist,intree,v);
		intree[u] = TRUE;
		for(int j=1;j<v;j++){
			if(intree[j] == FALSE && g[u][j] != 0 &&  dist[u]+ g[u][j] < dist[j]){
				//g[u][j] = weight
				dist[j] = dist[u]+ g[u][j];
				parent[j]= u ;
			}
		}
	}
		for(int i=1;i<v;i++){
		cout << dist[i] << " ";
	}
	cout << endl;
		for(int i=1;i<v;i++){
		cout << intree[i] << " ";
	}
	cout << endl;
	for(int i=1;i<v;i++){
		cout << parent[i] << " ";
	}
	cout << endl;
	
}
int main(){
	int n ,m;
	cin >> n >> m;
	vector<vector<int> > g(n+1,vector<int>(n+1,0));
	while(true){
		int u ,v,w;
		cin >> u >> v >> w;
		if(u==0){
			break;
		}
		g[v][u] = w;
		g[u][v] = w;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << g[i][j] << "  ";
			
		}
		cout << endl;
	}
	dijkstra( g,n+1,1);
}
