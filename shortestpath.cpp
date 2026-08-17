#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

void solve() {
    int R; cin >> R;
    map<int, vector<pair<int,int>>> g;
    set<int> vis;

    while(R--) {
        int src, dest, dist;
        cin >> src >> dest >> dist;
        g[src].push_back({dest, dist});
        g[dest].push_back({src, dist});
    }

    int st, end; cin >> st >> end;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, st});

    while(!pq.empty()) {
        auto[currdist,city] = pq.top();
        pq.pop();

        if(!vis.contains(city)) {
            vis.insert(city);
            if(city == end) {
                cout << currdist << endl;
                return;
            }
            for(auto [oc, ocd] : g[city]) {
                if(!vis.contains(oc)) {
                    pq.push({currdist + ocd, oc});
                }
            }
        }
    }

    cout << "City " << end << " cannot be reached from City " << st << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
