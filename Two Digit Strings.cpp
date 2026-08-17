#include<iostream>
#include<vector>
using namespace std;
void solve(){
		string a,b;
		cin>>a>>b;
		int r=a.length();
		int c=b.length();
		vector<int>pa(r+1,0),pb(c+1,0);
		for(int i=1;i<=r;i++){
			pa[i]=(pa[i-1]+(a[i-1]-'0'))%10;
		}
		for(int i=1;i<=c;i++){
			pb[i]=(pb[i-1]+(b[i-1]-'0'))%10;
		}
		if(pa[r]!=pb[c]){
			cout<<"-1"<<endl;
			return;
		}	
			vector<vector<int>>dp(r+1,vector<int>(c+1,0));
			for(int row=1;row<=r;row++){
				for(int col=1;col<=c;col++){
					if(pa[row-1]==pb[col-1]){
						dp[row][col]=1+dp[row-1][col-1];
					}
					else{
						dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
					}
				}
			}
			cout<< dp[r][c]<<endl;
		}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
}