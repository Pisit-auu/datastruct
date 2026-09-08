#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;  
    list<pair<int, int> >* adj;  

public:
    Graph(int V); 
    void addEdge(int u, int v, int weight);

    void DFS(int startVertex);

    void DFSUtil(int v, bool visited[]);

    void BFS(int startVertex);
};


Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int> >[V];
}


void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));  
}


void Graph::DFSUtil(int v, bool visited[]) {
	adj[v].sort(); 

    visited[v] = true;
    cout << v << " ";  

    for (list<pair<int, int> >::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        int neighbour = (*i).first;  
        if (!visited[neighbour])
            DFSUtil(neighbour, visited);
    }
}

void Graph::DFS(int startVertex) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(startVertex, visited);
    cout << endl; 
}

void Graph::BFS(int startVertex) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (list<pair<int, int> >::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
            int neighbour = (*i).first;
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Graph g(n);

    char command;
    while (true) {
        cin >> command;

        if (command == 'e') {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (command == 's') {

        } else if (command == 'd') {
            int startVertex;
            cin >> startVertex;
            g.DFS(startVertex);
        } else if (command == 'b') {
            int startVertex;
            cin >> startVertex;
            g.BFS(startVertex);
        } else if (command == 'q') {
            break;
        }
    }

    return 0;
}

