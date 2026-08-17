#include<iostream>
#include<set>
using namespace std;
void solve(){
	int L,Q;
	cin>>L>>Q;
	set<int>st={0,L};
	while(Q--){
		int qt,x;
		cin>>qt>>x;
		if(qt==1)st.insert(x);
		else{
			auto it=st.lower_bound(x);
			cout<<*it-*(prev(it))<<endl;
		}
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