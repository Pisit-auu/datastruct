#include <bits/stdc++.h>
using namespace std;
#define INF 50000
typedef pair<int, int> node;

int counttime = 0;
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};
bool checkend = true;
void findexit(vector<vector<char> >& graph, int n, int m, int x, int y) {

    if (x < 0 || y < 0 || x >= n || y >= m || graph[x][y] == 'X') {
        return;
    }

    if (graph[x][y] == 'D') {
    	checkend = false;
        return; 
    }

    if (graph[x][y] != 'S') {
    	cout << graph[x][y]<<endl;
        counttime += graph[x][y] - '0'; 
    }


    graph[x][y] = 'X';
    int keepgox = -1, keepgoy = -1;
    int min = 100000;  

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && graph[nx][ny] != 'X') {
            int time_to_move = (graph[nx][ny] == 'D') ? 0 : graph[nx][ny] - '0';
            if (time_to_move < min) {
                min = time_to_move;
                keepgox = nx;
                keepgoy = ny;
            }
        }
    }
    if (keepgox != -1 && keepgoy != -1) {
        findexit(graph, n, m, keepgox, keepgoy);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char> > graph(n, vector<char>(m)); 
    
    int startX, startY, endX, endY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            
            if (graph[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (graph[i][j] == 'D') {
                endX = i;
                endY = j;
            }
        }
    }
    
    findexit(graph, n, m, startX, startY);
    
    cout << counttime << endl;

    return 0;
}

