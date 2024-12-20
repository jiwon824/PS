import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        br.close();

        // 하노이 탑에서 원판 갯수가 N일 때, 최소 이동 횟수는 2^N-1번. 1<<N==2^N
        sb.append((1<<n)-1).append('\n');

        hanoi(n, 1, 2, 3);

        System.out.println(sb);
    }

    public static void hanoi(int n, int start, int bypass, int to){
        // 이동할 원판의 갯수가 1개인 경우
        if(n==1) {
            sb.append(start).append(" ").append(to).append('\n');
            return;
        }

        // 1. n-1개의 원판을 3번 장대를 거쳐 2번 장대로 옮기고,
        hanoi(n-1, start, to, bypass);

        // 2. 1번 장대에 있는 가장 큰 크기의 원판을 3번 장대로 옮긴 후,
        sb.append(start).append(" ").append(to).append('\n');

        // 3. 2번 장대에 있는 n-1개의 원판을 1번 장대를 거쳐 3번 장대로
        hanoi(n-1, bypass, start, to);
    }
}
