#include <bits/stdc++.h>


using namespace std;

typedef pair<int, int> Node;


bool compare(const Node &a, const Node &b) {
    return a.second < b.second;
}

int main() {
    int n, cpuCount = 3;
    cin >> n;

    vector<Node> programs(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        programs[i] = make_pair(start, end);
    }

    sort(programs.begin(), programs.end(), compare);

    priority_queue<int, vector<int>, greater<int> > pq; 
    int maxPrograms = 0;

    for (int  i = 0; i < programs.size(); i++) {
        int start = programs[i].first;
        int end = programs[i].second;
        cout << start << " " << end <<endl;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); 
        }

        if (pq.size() < cpuCount) {
            pq.push(end); 
            maxPrograms++;
        }
    }

    cout  << maxPrograms << endl;

    return 0;
}

