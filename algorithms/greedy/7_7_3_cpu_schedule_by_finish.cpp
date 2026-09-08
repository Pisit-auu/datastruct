#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Node;

bool sortmin(const Node &a, const Node &b) {
    return a.second < b.second; 
}

int main() {
    int n;
    cin >> n;

    vector<Node> Cpu(n);
    for (int i = 0; i < n; i++) {
        float start, end;
        cin >> start >> end;
        Cpu[i] = {start, end};
    }

    sort(Cpu.begin(), Cpu.end(), sortmin);

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < Cpu.size(); i++) {
        cout << Cpu[i].first << " " << Cpu[i].second << endl;
        int start = Cpu[i].first;
        int end = Cpu[i].second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
        
    }

    cout << pq.size() << endl;

    return 0;
}

