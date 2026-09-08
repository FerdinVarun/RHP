import java.util.Scanner;

  public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int R = sc.nextInt();
        int C = sc.nextInt();

        int[][] grid = new int[R][C];
        long[][] dp = new long[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = sc.nextInt();

                if (j == 0) {
                    dp[i][j] = grid[i][j];
                }
            }
        }

        for (int j = 1; j < C; j++) {

            long firstMax = Long.MIN_VALUE;
            long secondMax = Long.MIN_VALUE;

            for (int i = 0; i < R; i++) {

                if (dp[i][j - 1] > firstMax) {
                    secondMax = firstMax;
                    firstMax = dp[i][j - 1];
                }
                else if (dp[i][j - 1] > secondMax) {
                    secondMax = dp[i][j - 1];
                }
            }

            for (int i = 0; i < R; i++) {

                if (dp[i][j - 1] == firstMax) {
                    dp[i][j] = grid[i][j] + secondMax;
                } else {
                    dp[i][j] = grid[i][j] + firstMax;
                }
            }
        }

        long ans = dp[0][C - 1];

        for (int i = 1; i < R; i++) {
            if (dp[i][C - 1] > ans) {
                ans = dp[i][C - 1];
            }
        }

        System.out.println(ans);
    }
}
