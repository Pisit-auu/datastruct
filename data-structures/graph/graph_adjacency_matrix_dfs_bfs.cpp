#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class graph {
public:
    int** arr; 
    int count; 

    graph(int n) {
        arr = new int*[n];
        count = n;
        for (int i = 0; i < n; i++) {
            arr[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
    }

    void addedge(int v, int m,int w) {
        arr[v][m] = w; 
    }
    /*
    void print() {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
*/

 
    void DFS(int start) {
        bool* visited = new bool[count]; 
        for (int i = 0; i < count; i++)
            visited[i] = false; 

        stack<int> s; 
        s.push(start); 

        while (!s.empty()) {
            int v = s.top(); 
            s.pop(); 

            if (!visited[v]) {
                visited[v] = true; 
                cout << v << " "; 

      
                for (int i = count - 1; i >= 0; i--) {
                    if (arr[v][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        delete[] visited; 
    }

    void BFS(int start) {
        bool* visited = new bool[count]; 
        for (int i = 0; i < count; i++)
            visited[i] = false; 

        queue<int> q; 
        q.push(start); 
        visited[start] = true; 

        while (!q.empty()) {
            int v = q.front(); 
            q.pop();
            cout << v << " "; 

            for (int i = 0; i < count; i++) {
                if (arr[v][i] !=0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true; 
                }
            }
        }
        delete[] visited; 
    }

};

int main() {
	int v,m,w;
	cin >> v;
	
    graph* g = new graph(v);
    char c;
    bool checks =true ;
    do{
    	cin >> c;
    	switch(c){
    		case 'e':{
    			if(checks){
    				cin>>v;
    				cin>>m;
    				cin>>w;
    				g->addedge(v,m,w);
				}
				break;
			}
			case 's':{
				checks =false;
				break;
			}
			case 'd':{
				cin>>v;
				g->DFS(v); 
				cout <<endl;
				break;
			}
			case 'b':{
					cin>>v;
				 g->BFS(v); 
				 cout <<endl;
				break;
			}
		}
    	
	}while(c!='q');
    return 0;
}

