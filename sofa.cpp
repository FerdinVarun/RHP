#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class sofa
{
public:
    int r1 , c1 , r2 , c2;
    char dir;
    int steps;

        sofa(int r1 , int c1 , int r2 , int c2 , char dir , int cnt)
        {
            this->r1 = r1;
            this->c1 = c1;
            this->r2 = r2;
            this->c2 = c2;
            this->dir = dir;
            this->steps = cnt;
        }

};
bool canAdd(int r1 , int c1 , int r2 , int c2 , set<string>& vis)
{
    string key = to_string(r1) + "_" + to_string(c1) + "_" + to_string(r2) + "_" + to_string(c2);

    if(vis.count(key)){
        return false;
    }
    else{
        vis.insert(key);
        return true;
    }
}
void solve()
{
    int R , C;
    cin >> R >> C;

    vector<string> grid(R , string(C , '0'));
    queue<sofa> q;
    set<string> vis;
    int r1 , c1 , r2 , c2 , cnt = 0;
    c1 = r1 = r2 = c2 = -1;
    for(int i = 0;i<R;i++)
        for(int j = 0;j<C;j++)
            cin >> grid[i][j];

    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            if(grid[i][j] == 's'){
                cnt++;
                if(cnt == 1){
                    r1 = i;c1 = j;
                }
                else{
                    r2 = i;c2 = j;
                    canAdd(r1 , c1 , r2 , c2 , vis);
                    q.push(sofa(r1 , c1 , r2 , c2 , (r1 == r2 ? 'H' : 'V') , 0 ));
                }
            }}}

            while(!q.empty())
            {
                sofa s = q.front();
                q.pop();
                if(grid[s.r1][s.c1] == 'S' && grid[s.r2][s.c2] == 'S'){
                    cout << s.steps << endl;return;
                }
                if(s.dir == 'H'){
                if(s.c2<C-1 && grid[s.r2][s.c2+1] != 'H'){
                    if(canAdd(s.r2 , s.c2 , s.r2 , s.c2+1 , vis))
                    {
                        q.push(sofa(s.r2 , s.c2 , s.r2 , s.c2+1 , 'H' , s.steps+1));
                    }
                }

                if(s.c1 > 0 && grid[s.r1][s.c1-1] != 'H'){
                    if(canAdd(s.r1 , s.c1-1 , s.r1 , s.c1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1-1 , s.r1 , s.c1 , 'H' , s.steps+1));
                    }
                }
                if(s.r1 > 0  && grid[s.r1-1][s.c1] != 'H' && grid[s.r2-1][s.c2] != 'H'){
                    if(canAdd(s.r1-1 , s.c1 , s.r2-1 , s.c2 , vis))
                    {
                        q.push(sofa(s.r1-1 , s.c1 , s.r2-1 , s.c2 , 'H' , s.steps+1));
                   }
                }
                if(s.r1 < R-1  && grid[s.r1+1][s.c1] != 'H' && grid[s.r2+1][s.c2] != 'H'){
                    if(canAdd(s.r1+1 , s.c1 , s.r2+1 , s.c2 , vis))
                    {
                        q.push(sofa(s.r1+1 , s.c1 , s.r2+1 , s.c2 , 'H' , s.steps+1));
                    }

                }

            }
                else if(s.dir == 'V')
                {
                if(s.r1 > 0 && grid[s.r1-1][s.c1] != 'H'){
                    if(canAdd(s.r1-1 , s.c1 , s.r1 , s.c1 , vis))
                    {
                        q.push(sofa(s.r1-1 , s.c1 , s.r1 , s.c1  , 'V' , s.steps+1));
                    }
                }
                if(s.r2 < R-1 && grid[s.r2+1][s.c2] != 'H'){
                    if(canAdd(s.r2 , s.c2 , s.r2+1 , s.c2 , vis))
                    {
                        q.push(sofa(s.r2 , s.c2 , s.r2+1 , s.c2 , 'V' , s.steps+1));
                    }
                }
                if(s.c2 < C-1  && grid[s.r1][s.c1+1] != 'H' && grid[s.r2][s.c2+1] != 'H'){
                    if(canAdd(s.r1 , s.c1+1 , s.r2 , s.c2+1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1+1 , s.r2 , s.c2+1 , 'V' , s.steps+1));
                   }
                }
                if(s.c1 > 0  && grid[s.r1][s.c1-1] != 'H' && grid[s.r2][s.c2-1] != 'H'){
                    if(canAdd(s.r1 , s.c1-1 , s.r2 , s.c2-1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1-1 , s.r2 , s.c2-1 , 'V' , s.steps+1));
                    }
                }


                }

                if(s.dir == 'H' && s.r1 < R-1 && grid[s.r1+1][s.c1] != 'H' && grid[s.r2+1][s.c2] != 'H'){
                    if(canAdd(s.r2 , s.c2 , s.r2+1 , s.c2 , vis))
                    {
                        q.push(sofa(s.r2 , s.c2 , s.r2+1 , s.c2 , 'V' , s.steps+1));
                    }

                    if(canAdd(s.r1 , s.c1 , s.r1+1 , s.c1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1 , s.r1+1 , s.c1 , 'V' , s.steps+1));
                    }
                }
                if(s.dir == 'H' && s.r1 > 0  && grid[s.r1-1][s.c1] != 'H' && grid[s.r2-1][s.c2] != 'H'){
                    if(canAdd(s.r2-1 , s.c2 , s.r2 , s.c2 , vis))
                    {
                        q.push(sofa(s.r2-1 , s.c2 , s.r2 , s.c2 , 'V' , s.steps+1));
                    }

                    if(canAdd(s.r1-1 , s.c1 , s.r1 , s.c1 , vis))
                    {
                        q.push(sofa(s.r1-1 , s.c1 , s.r1 , s.c1 , 'V' , s.steps+1));
                    }
                }



                if(s.dir == 'V' && s.c1 < C-1 && grid[s.r1][s.c1+1] != 'H' && grid[s.r2][s.c2+1] != 'H'){
                    if(canAdd(s.r1 , s.c1 , s.r1 , s.c1+1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1 , s.r1 , s.c1+1, 'H' , s.steps+1));
                    }

                    if(canAdd(s.r2 , s.c2 , s.r2 , s.c2+1 , vis))
                    {
                        q.push(sofa(s.r2 , s.c2 , s.r2 , s.c2+1 , 'H' , s.steps+1));
                    }
                }
                if(s.dir == 'V' && s.c1 > 0  && grid[s.r1][s.c1-1] != 'H' && grid[s.r2][s.c2-1] != 'H'){
                    if(canAdd(s.r1 , s.c1-1 , s.r1 , s.c1 , vis))
                    {
                        q.push(sofa(s.r1 , s.c1-1 , s.r1 , s.c1 , 'H' , s.steps+1));
                    }

                    if(canAdd(s.r2 , s.c2-1 , s.r2 , s.c2 , vis))
                    {
                        q.push(sofa(s.r2 , s.c2-1 , s.r2 , s.c2 , 'H' , s.steps+1));
                    }
                }

    }
    cout << "Impossible" << endl;

}
int main()
{
	ios::sync_with_stdio(true);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--){
    	solve();
	}
}
