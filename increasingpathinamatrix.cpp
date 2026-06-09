#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int diff[4][2] = {
    {0, -1},  // Left
    {0, 1},   // Right
    {-1, 0},  // Up
    {1, 0}    // Down
};

int dfs(vector<vector<int>>& matrix,
        vector<vector<int>>& dp,
        int R, int C,
        int row, int col)
{
    if (dp[row][col] != 0)
        return dp[row][col];

    int adjMax = 0;
    for (int i = 0; i < 4; i++)
    {
        int ar = row + diff[i][0];
        int ac = col + diff[i][1];
        if (ar >= 0 && ar < R &&
            ac >= 0 && ac < C &&
            matrix[ar][ac] > matrix[row][col])
        {
            adjMax = max(adjMax,
                         dfs(matrix, dp, R, C, ar, ac));
        }
    }
    dp[row][col] = 1 + adjMax;

    return dp[row][col];
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    vector<vector<int>> dp(R, vector<int>(C, 0));

    int maxLen = 1;

    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            maxLen = max(maxLen,
                         dfs(matrix, dp, R, C, row, col));
        }
    }

    return maxLen;
}

int main()
{
    int R, C;

    cout << "Enter rows and columns: ";
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Longest Increasing Path Length = "
         << longestIncreasingPath(matrix)
         << endl;

    return 0;
}