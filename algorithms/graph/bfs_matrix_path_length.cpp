#include <bits/stdc++.h>
using namespace std;
int numcount=0;
void BFS(int start,int n,vector<vector<int> > graph,int findend){
	queue<int> q;
	vector<bool> visit(n+1,false);
	vector<int > parent(n+1,-1);
	q.push(start);
	visit[start]= true;
	while(!q.empty()){
		int a = q.front();
		q.pop(); 
		cout << a<< " ";
		for(int i=1;i<=n;i++){
			if(!visit[i]&&graph[a][i]!=0){
				q.push(i);
				visit[i] = true;
				parent[i]= a;
			}
		}
	}
	cout << endl;
	
	int indexfind = findend;
	while(parent[indexfind]!=-1){
		indexfind = parent[indexfind];
		numcount++;
	}
	
}

int main(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	for(int i=0;i<n;i++){
		int u;
		cin>> u;
		int v;
		while(true){
			cin >> v;
			if(v==0){
				break;
			}
			graph[u][v]=1;
		}
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << graph[i][j] <<" ";
		}
		cout <<endl;
	}
	int start,findend;
    cin >> start>>findend;
    BFS(start, n, graph,findend);
    cout <<numcount;

}
