#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int
#define INF 2e9
using namespace std;

void solve(){
	int N; cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++) cin >> a[i];
	sort(a.begin(),a.end());
	
	vector<int> ans;
	ll cf=0LL;
	for(int ctr=1;ctr<=a[N-1];ctr++){
		auto it=lower_bound(a.begin(),a.end(),ctr);
		int cnt=a.end()-it;
		cf+=cnt;
		ans.push_back(cf%10);
		cf=cf/10;
	}
	while(cf>0){
		ans.push_back(cf%10);
		cf=cf/10;
	}
	reverse(ans.begin(),ans.end());
	for(int d:ans) cout << d;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	while(tc--) solve();
}