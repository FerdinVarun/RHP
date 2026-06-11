#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    cout<<"Enter the string 1: ";
    getline(cin,s1);
    cout<<"Enter the string 2: ";
    getline(cin,s2);
    int a=s1.length();
    int b=s2.length();
    int maxi=0;
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}