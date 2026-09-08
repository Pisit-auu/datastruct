#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > Node;
bool sortmax(const Node &a, const Node &b) {
    return a.first > b.first; 
}
int main() {
    int n;
    cin >> n;

    vector<Node> Cpu(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        Cpu[i] = {end-start,{start, end}};
    }

    sort(Cpu.begin(), Cpu.end(), sortmax);

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < Cpu.size(); i++) {
    	cout <<"average : "<<Cpu[i].first <<" "<< Cpu[i].second.first <<" " << Cpu[i].second.second <<endl;
        int start = Cpu[i].second.first;
        int end = Cpu[i].second.second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
    }

    cout << pq.size() << endl;

    return 0;
}

