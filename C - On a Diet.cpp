#include<iostream>
#include<vector>
#define ll unsigned long long int
using namespace std;
void solve(){
	int N,M;ll K;
	cin>>N>>M>>K;
	vector<int>arr(N);
	vector<bool>eaten(N,false);
	for(int i=0;i<N;i++)cin>>arr[i];
	ll curr=0;
	for(int i=0;i<N;i++){
		if(i>=M){
			if(eaten[i-M]){
				curr-=arr[i-M];
			}
		}
		if(arr[i]+curr<=K){
			cout<<"Yes"<<endl;
			eaten[i]=true;
			curr+=arr[i];
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	while(t--){
		solve();
	}
}