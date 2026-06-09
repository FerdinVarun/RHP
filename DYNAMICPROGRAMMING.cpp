#include <iostream>
#include <vector>
using namespace std;

pair<long long, long long> getFSMax(vector<vector<long long>>& dp,
                                    int row,
                                    int C)
{
    long long fmax = max(dp[row][0], dp[row][1]);
    long long smax = min(dp[row][0], dp[row][1]);

    for (int col = 2; col < C; col++)
    {
        if (dp[row][col] > fmax)
        {
            smax = fmax;
            fmax = dp[row][col];
        }
        else if (dp[row][col] > smax)
        {
            smax = dp[row][col];
        }
    }

    return {fmax, smax};
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<long long>> dp(R, vector<long long>(C, 0));

    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            cin >> grid[row][col];

            if (row == 0)
            {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int row = 1; row < R; row++)
    {
        auto [fmax, smax] = getFSMax(dp, row - 1, C);

        for (int col = 0; col < C; col++)
        {
            dp[row][col] =
                grid[row][col] +
                (dp[row - 1][col] == fmax ? smax : fmax);
        }
    }

    auto [answer, temp] = getFSMax(dp, R - 1, C);

    cout << answer << endl;

    return 0;
}