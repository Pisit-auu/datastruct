#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Node;

int main() {
    int n;
    cin >> n;

    vector<Node> Cpu(n);
    for (int i = 0; i < n; i++) {
        float start, end;
        cin >> start >> end;
        Cpu[i] = {start, end};
    }

    sort(Cpu.begin(), Cpu.end());

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < Cpu.size(); i++) {
    	cout << Cpu[i].first <<" " << Cpu[i].second <<endl;
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

