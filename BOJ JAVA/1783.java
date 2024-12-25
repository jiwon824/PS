import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        br.close();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 병든 나이트는 여행을 시작하려고 하고, 여행을 하면서 방문한 칸의 수를 최대로 하려고 한다.
            // 이동 횟수가 4번보다 적은 경우(방문한 칸이 5개 미만)에는 이동 방법에 대한 제약이 없다.
            // 병든 나이트의 이동 횟수가 4번 이상이라면, 이동 방법을 모두 한 번씩 사용해야 한다.
        // 세로3 가로7이 되어야 4번 이상 방문 가능
        if (n==1) System.out.println(1);
        else if(n==2) System.out.println(Math.min(4, (m+1)/2));
        else{
            if(m<7){
                System.out.println(Math.min(4, m));
            } else{
                System.out.println(m-2);
            }
        }

    }
}
