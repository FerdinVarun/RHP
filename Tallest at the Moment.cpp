#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
	int N;
	cin>>N;
	vector<pair<int,int>>arr(N);
	for(int i=0;i<N;i++){
		int lt,ht;
		cin>>ht>>lt;
		arr[i]=make_pair(ht,lt);
	}
	sort(arr.begin(),arr.end(),greater<>());
	int prev=0;
	vector<int>htarr,ltarr;
	for(auto [ht,lt]:arr){
		if(lt>prev){
			prev=lt;
			htarr.push_back(ht);
			ltarr.push_back(lt);
		}
	}
	int Q;cin>>Q;
	while(Q--){
		int t;cin>>t;
		auto it=upper_bound(ltarr.begin(),ltarr.end(),t);
		int indx=it-ltarr.begin();
		cout<<htarr[indx]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	while(tc--){
		solve();
	}
}