#include<iostream>
#include<set>
using namespace std;
void solve(){
  int n; cin>>n;
  set<int> m;
  while(n--){
      int x;
      cin>>x;
      m.insert(x);
  }
  cout<<m.size()<<endl;
  for(int i:m){
      cout<<i<<" ";
  }
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