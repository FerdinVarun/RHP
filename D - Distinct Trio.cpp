#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long int
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;

    for (int i = 1; i < N-1; i++) {
        auto ubit = upper_bound(arr.begin(), arr.end(), arr[i]);
        int high=arr.end()-ubit;
        auto lbit = lower_bound(arr.begin(), arr.end(), arr[i]);
        int low=lbit-arr.begin();
        ans+=1LL*high*low;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int tc=1;
	while(tc--){
		
    	solve();
    }
    return 0;
}

