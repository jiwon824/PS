import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 테스트 케이스의 개수 tc
        int n = sc.nextInt();

        // dp[i][j]: 자릿수가 i인 경우 중 숫자 j로 끝나는 계단수의 수
        // dp[1][9]: 1자릿수, 9로 끝나는 수 = {9} 1가지
        // dp[2][8]: 2자릿수, 8로 끝나는 수 = {78, 98} 2가지
        int[][] dp = new int[n+1][10];

        //초기값
        dp[1][0]=0;// 0으로 시작하는 수는 계단 수가 아님
        for(int j=1; j<=9; j++){
            dp[1][j]=1;
        }

        // 전개: 정수 n이 주어진다. n은 양수이며 11보다 작다
        for(int i=2; i<=n; i++){
            for(int j=1; j<=8; j++){
                //1,000,000,000으로 나눈 나머지를 출력
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]) % 1_000_000_000;
            }
            dp[i][0]=dp[i-1][1];
            dp[i][9]=dp[i-1][8];
        }
        
        // output
        int answer=0;
        for(int j=0; j<=9; j++){
            answer+=dp[n][j];
            answer%= 1_000_000_000;
        }
        System.out.println(answer);
    }
}
