import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int[] withdrawalTime;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다.
        int n = Integer.parseInt(br.readLine());
        withdrawalTime = new int[n];
        // 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            withdrawalTime[i]= Integer.parseInt(st.nextToken());
        }
        br.close();

        Arrays.sort(withdrawalTime);
        
        int answer = 0;
        int waitingTime =0;
        for (int i = 0; i < n; i++) {
            waitingTime+=withdrawalTime[i];
            answer += waitingTime;
        }
        System.out.println(answer);
    }
}
