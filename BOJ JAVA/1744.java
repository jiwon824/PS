import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Integer> pos = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> neg = new PriorityQueue<>();

        // 첫째 줄에 수열의 크기 N이 주어진다. N은 50보다 작은 자연수이다.
        int n = Integer.parseInt(br.readLine());
        // 둘째 줄부터 N개의 줄에 수열의 각 수가 주어진다. 수열의 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            if(num>0) pos.add(num);
            else neg.add(num);
        }
        br.close();

        int answer = getSum(pos)+getSum(neg);
        System.out.println(answer);
    }

    public static int getSum(PriorityQueue<Integer> pq) {
        int sum = 0;

        // 큐에 두 개 이상의 요소가 있을 때만 처리
        while (pq.size() > 1) {
            int curr = pq.poll();
            int next = pq.poll();

            if (curr == 1 || next == 1) {
                sum += curr + next; // 두 값 중 하나라도 1이면 더하기
            } else {
                sum += curr * next; // 그렇지 않으면 곱하기
            }
        }

        // 마지막 남은 요소 처리
        if (!pq.isEmpty()) {
            sum += pq.poll();
        }

        return sum;
    }
}
