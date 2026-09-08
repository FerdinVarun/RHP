import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s1 = sc.nextLine();
        String s2 = sc.nextLine();

        int n = s1.length();
        int m = s2.length();

        int[][] dp = new int[n + 1][m + 1];

        int maxLength = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {

                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                    }

                } else {

                    dp[i][j] = 0;
                }
            }
        }

        System.out.println(maxLength);
    }
}
