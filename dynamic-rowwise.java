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

                if (i == 0) {
                    dp[i][j] = grid[i][j];
                }
            }
        }

        for (int i = 1; i < R; i++) {

            long firstMax = Long.MIN_VALUE;
            long secondMax = Long.MIN_VALUE;

            for (int j = 0; j < C; j++) {
                if (dp[i - 1][j] > firstMax) {
                    secondMax = firstMax;
                    firstMax = dp[i - 1][j];
                } else if (dp[i - 1][j] > secondMax) {
                    secondMax = dp[i - 1][j];
                }
            }

            for (int j = 0; j < C; j++) {

                if (dp[i - 1][j] == firstMax) {
                    dp[i][j] = grid[i][j] + secondMax;
                } else {
                    dp[i][j] = grid[i][j] + firstMax;
                }
            }
        }

        long ans = dp[R - 1][0];

        for (int j = 1; j < C; j++) {
            if (dp[R - 1][j] > ans) {
                ans = dp[R - 1][j];
            }
        }

        System.out.println(ans);
    }
}
