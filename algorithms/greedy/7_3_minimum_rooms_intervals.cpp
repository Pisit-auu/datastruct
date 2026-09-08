#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<float, float> Node;

int main() {
    int n;
    cin >> n;

    vector<Node> station(n);
    for (int i = 0; i < n; i++) {
        float start, end;
        cin >> start >> end;
        station[i] = {start, end};
    }

    sort(station.begin(), station.end());
//	  for (int i = 0; i < n; i++) {
//        cout<< station[i].first<< " " << station[i].second <<endl; 
//    }

    priority_queue<float, vector<float>, greater<float> > pq;

    for (int i = 0; i < station.size(); i++) {
        float start = station[i].first;
        float end = station[i].second;


        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
    }

    cout << pq.size() << endl;

    return 0;
}

