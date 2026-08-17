#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int diff[5]={0,-1,0,1,0};
void dfs(vector<string>&g,int row,int col,int R,int C){
	g[row][col]='#';
	for(int i=0;i<4;i++){
		int ar=row+diff[i],ac=col+diff[i+1];
		if(ar>=0&&ar<R&&ac>=0&&ac<C&&g[ar][ac]=='.'){
			dfs(g,ar,ac,R,C);
		}
	}
}
void solve(){
	int r,c;
	cin>>r>>c;
	vector<string> g(r);
	for(int i=0;i<r;i++)
	{
		cin>>g[i];
	}
		int rooms=0;
	for(int row=0;row<r;row++){
		for(int col=0;col<c;col++){
			if(g[row][col]=='.'){
				rooms++;
				dfs(g,row,col,r,c);
			}
		}
	}
	cout<<rooms<<endl;
	}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int t=1;
    while(t--){
    	solve();
    }
    return 0;
}