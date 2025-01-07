import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    public static int t;

    // A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫째 줄에 T(-1,000,000,000 ≤ T ≤ 1,000,000,000)가 주어진다.
        t = Integer.parseInt(br.readLine());
        // 다음 줄에는 n(1 ≤ n ≤ 1,000)이 주어지고,
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        // 그 다음 줄에 n개의 정수로 A[1], …, A[n]이 주어진다.
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        // 다음 줄에는 m(1 ≤ m ≤ 1,000)이 주어지고,
        int m = Integer.parseInt(br.readLine());
        int[] b = new int[m];
        // 그 다음 줄에 m개의 정수로 B[1], …, B[m]이 주어진다. 각각의 배열 원소는 절댓값이 1,000,000을 넘지 않는 정수이다.
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        br.close();

        Map<Integer, Integer> aPartialSum = calculatePartialSum(a);;
        Map<Integer, Integer> bPartialSum = calculatePartialSum(b);;

        long answer =0;
        for (Map.Entry<Integer, Integer> entry : aPartialSum.entrySet()) {
            int sumA = entry.getKey();
            int countA = entry.getValue();
            int target = t -sumA;
            if(bPartialSum.containsKey(target)){
                answer += (long) countA * bPartialSum.get(target);
            }
        }

        // 첫째 줄에 답을 출력한다. 가능한 경우가 한 가지도 없을 경우에는 0을 출력
        System.out.println(answer);
    }

    public static Map<Integer,Integer> calculatePartialSum(int[] arr){
        Map<Integer, Integer> sumCount = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                sum+= arr[j];
                sumCount.put(sum, sumCount.getOrDefault(sum, 0)+1);
            }
        }
        return sumCount;
    }

}
