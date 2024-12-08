import java.util.Scanner;

public class Main {
    public static final int MAX_N = 200;
    public static final int MAX_K = 200;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int[][] dp = new int[MAX_N+1][MAX_K+1];

        // 초기값
        for (int i = 1; i <=n ; i++) {
            dp[i][1]=1;
        }

        for (int j = 1; j <= k; j++) {
            dp[1][j]=j;
        }

        // 전개
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                // 1,000,000,000으로 나눈 나머지를 출력
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]) % 1_000_000_000;
            }
        }

        // output
        System.out.println(dp[n][k]);
    }
}
