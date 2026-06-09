#include<iostream>
#include<vector>
using namespace std;
int diff[4][2]={
    {-1,0},
    {0,-1},
    {0,1},
    {1,0}
};
void dfs(vector<vector<int>>& grid, int R, int C, int row, int col) {
    grid[row][col] = 0; // Mark the cell as visited
    for(int i=0;i<4;i++){
        int ar=row+diff[i][0];
        int ac=col+diff[i][1];
        if(ar>=0 && ar<R && ac>=0 && ac<C && grid[ar][ac]==1){
            dfs(grid,R,C,ar,ac);
        }
    }

}
int numIslands(vector<vector<int>>& grid){
    int R=grid.size();
    int C=grid[0].size();
    int islands=0;
    for(int row=0;row<R;row++){
        for(int col=0;col<C;col++){
            if(grid[row][col]==1){
                islands++;
                dfs(grid,R,C,row,col);
            }
        }
    }
    return islands;
}
int main(){
    int C,R;
    cout<<"Enter the number of rows and columns: ";
    cin>>R>>C;
    vector<vector<int>> grid (R,vector<int>(C));
    cout<<"Enter the elements of the grid: "<<endl;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Number of islands: "<<numIslands(grid)<<endl;
}