#include <bits/stdc++.h>
using namespace std;
int countpaint =0;
	int n,m;
void DFS(vector<vector<char> > &graphint,int x,int y) {
		if (x < 1 || x > n || y < 1 || y > m || graphint[x][y] != 'W') {
        return;
    }
 		if(graphint[x][y]=='W'){
 			countpaint++;
 			graphint[x][y]='G';
		 }
		 DFS(graphint,x,y-1);
		 DFS(graphint,x+1,y);
		 DFS(graphint,x,y+1);
		 DFS(graphint,x-1,y);
}
int main(){

	cin >> n >> m;
	vector<vector<char> >graph(n+1, vector<char> (m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> graph[i][j];
		}
	}
	int x,y;
	cin >> x >>y;
	DFS(graph,x,y); 
	cout <<countpaint;
}
