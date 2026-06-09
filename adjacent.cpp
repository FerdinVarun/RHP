#include<iostream>
#include<vector>
using namespace std;
int main(){
    int R,C;
    cout<<"Enter the number of rows and columns: ";
    cin>>R>>C;
    vector<vector<int>> grid (R,vector<int>(C));
    cout<<"Enter the elements of the grid: "<<endl;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
        }
    }
    int diff[8][2]={
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},          {0,1},
        {1,-1},  {1,0},  {1,1}
    };
    cout<<"Enter the position (row and column) to find adjacent sum: ";
    int r,c;
    cin>>r>>c;
    long long sum=0;
    for(int i=0;i<8;i++){
        int ar=r+diff[i][0];
        int ac=c+diff[i][1];
        if(ar>=0 && ar<R && ac>=0 && ac<C){
            sum+=grid[ar][ac];
        }
    }
    cout<<"The sum of adjacent elements is: "<<sum<<endl;
    return 0;
}