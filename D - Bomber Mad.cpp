#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void solve(){
	int R , C , K;
	cin >> R >> C >> K;
	
	vector<string> grid(R);
	
	for(int i = 0;i<R;i++)
	{
		cin >> grid[i];
	}
	
	vector<vector<bool>> visted(R,vector<bool>(C,false));
	vector<bool> row_b(R,false) , col_b(C,false);
	queue<pair<int,int>> q;
	
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			if(grid[i][j] == '#')
			row_b[i] = col_b[j] = true;
		}
	}
	
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			if(!row_b[i] && !col_b[j])
			{
				visted[i][j] = true;
				q.push({i,j});
			}
		}
	}
	
	int hops = 0 , count = 0;
	int dir[5] = {0,1,0,-1,0};
	while(!q.empty() && hops<=K)
	{
		hops++;
		int size = q.size();
		count+=size;
		while(size--)
		{
			auto[row , col] = q.front();
			q.pop();
			
			for(int i = 0;i<4;i++)
			{
				int ar = row + dir[i];
				int ac = col + dir[i+1];
				
				if(ar>=0 && ac>=0 && ar < R && ac < C && !visted[ar][ac] && grid[ar][ac] == '.')
				{
					visted[ar][ac] = true;
					q.push({ar,ac});
				}
			}
		}
		
		
	}
	cout << count << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	while(tc--){
		solve();
	}
	return 0;
}