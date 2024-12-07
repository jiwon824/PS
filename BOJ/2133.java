import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // 홀수는 만들 수 없음
        if(n%2!=0){
            System.out.println(0);
            return;
        }

        int[] dp = new int[n+10];

        // 초기값
        dp[0]=1;// 아무것도 채우지 않는 경우 1개(아무 블럭도 배치하지 않으면 됨)
        dp[1]=0;
        dp[2]=3;

        // 전개
        for (int i = 4; i <= n; i+=2) {
            dp[i]=dp[2]*dp[i-2];

            // dp[0]*2= 각 단계에서만 나오는 특수 경우
            // dp[2]~dp[i-4] * 2는
            // dp[2]*dp[i-2]와 dp[i-2]*dp[2]에서 중복 경우를 제외한 경우
            // 즉 특수한 2가지 경우를 좌우반전한 경우를 의미
            for (int j = 0; j <= i-4 ; j+=2) {
                dp[i] += dp[j]*2;
            }
        }

        // output
        System.out.println(dp[n]);
    }
}
