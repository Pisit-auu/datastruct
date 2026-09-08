#include <bits/stdc++.h>
using namespace std;
int numcount=0;
bool hasCycle = false;

void DFS(int start,int n,vector<int>& parent,vector<bool>& visit,vector<vector<int> > graph){
	cout << start<<" ";
	visit[start] = true;
	 for (int i = 1; i <= n; i++) {
        if (graph[start][i] == 1) { // มีเส้นเชื่อม
            if (!visit[i]) {
                parent[i] = start;
                DFS(i, n, parent, visit, graph);
            } else if (parent[start] != i) { // ตรวจจับ cycle
                hasCycle = true;
            }
        }
	
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
	int start;
    cin >> start;
    vector<int> parent(n+1,-1);
    vector<bool> visit(n+1,false);
    DFS(start, n,parent,visit, graph);
        if (hasCycle) {
        cout << "Graph has a cycle" << endl;
    } else {
        cout << "Graph has no cycle" << endl;
    }


}
