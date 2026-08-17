#include<iostream>
#include<vector>
using namespace std;
void solve(){
  int n,m;cin>>n>>m;
  vector<int>p(n+2,0);
  while(m--){
    int f,t;
    cin>>f>>t;
    p[f]++;
    p[t+1]--;
  }
  int mi=200008;
  for(int i=1;i<=n;i++){
    p[i]+=p[i-1];
    mi=min(mi,p[i]);
  }
  cout<<mi<<endl;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); 
    int t=1;
    while(t--)
    {
    solve();
    }
}
//g++ -Wall -std=c++23