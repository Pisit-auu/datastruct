#include <bits/stdc++.h>
using namespace std;
#define INF 50000
typedef pair<int,int> node;
float N=0;
float sum=0;
void prim(vector<pair<int,int> > adj[],int V,int src){
	priority_queue< pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > pq;
	vector<int> dist(V,INF);
	vector<int> parent(V,-1);
	vector<bool> intree(V,false);
	pq.push( {0,src} );  
	dist[src] =0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		intree[u] = true;
		for(int j=0;j<adj[u].size();++j){
			int v = adj[u][j].first;
			int w = adj[u][j].second;
			if(intree[v] == false &&  w < dist[v]){
				dist[v] =  w;
				pq.push({dist[v], v}); 
				parent[v] = u;
			}
			
		}
	}
	
    for (int i = 1; i < V; i++) {
           if(i!= src&&parent[i]!=-1){
           	 int find = i;	 
			N++;
           	 while(parent[find]!=-1){
//           	 	cout << parent[find] << "  " ;
           	 		find = parent[find];
           	 		sum++;
				}
		   }
		   	   
			}
//	cout << endl;
}
int main(){
	
	int n;
	cin >> n;
	vector<node> g[n+1];
		int u,v;
	while(true){
		cin >> u >> v;
		if(v==0){
			break;
		}
		g[u].push_back({v,1});
		
			
	}
		
	
	
	for(int i=1;i<=n;i++){
		cout << "i" <<i<< ": ";
		for(int j=0;j<g[i].size();j++){
			cout << "("<<g[i][j].first <<","<< g[i][j].second << ") ";
		}
		cout << endl;
	}
	for(int i=1;i<=n;i++){
		prim(g,n+1,i);
	}
	printf("%.3f",sum/N);
}
