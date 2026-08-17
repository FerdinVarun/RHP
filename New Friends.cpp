#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int find(vector<int>& ldr, int node) {
    if (ldr[node] != node) {
        ldr[node] = find(ldr, ldr[node]);
    }
    return ldr[node];
}

void join(vector<int>& ldr, int lt, int rt) {
    ldr[find(ldr, lt)] = find(ldr, rt);
}

void solve() {
    int N, E;
    cin >> N >> E;
    vector<int> ldr(N+1);
    for (int i = 1; i <= N; i++) ldr[i] = i;

    vector<pair<int,int>> edges;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        join(ldr, a, b);
    }

    vector<int> gcnt(N+1, 0), ecnt(N+1, 0);
    for (int i = 1; i <= N; i++) {
        gcnt[find(ldr, i)]++;
    }
    for (auto &e : edges) {
        int root = find(ldr, e.first);
        ecnt[root]++;
    }

    ll ans = 0;
    for (int node = 1; node <= N; node++) {
        if (find(ldr,node) == node) {
            ll c = (1LL * gcnt[node] * (gcnt[node] - 1) / 2) - ecnt[node];
            ans += c;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
