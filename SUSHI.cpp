#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N), B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    int ans = 0;

    while (i < N && j < M) {

        if (B[j] <= 2 * A[i]) {
            ans++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    cout << ans << '\n';

    return 0;
}