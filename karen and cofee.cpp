#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    const int MAXT = 200000;

    vector<int> diff(MAXT + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> cover(MAXT + 1, 0);

    for (int i = 1; i <= MAXT; i++) {
        cover[i] = cover[i - 1] + diff[i];
    }

    vector<int> admissible(MAXT + 1, 0);

    for (int i = 1; i <= MAXT; i++) {
        admissible[i] = (cover[i] >= k);
    }

    vector<int> pref(MAXT + 1, 0);

    for (int i = 1; i <= MAXT; i++) {
        pref[i] = pref[i - 1] + admissible[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}