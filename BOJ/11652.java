import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // key: 적혀있는 수는 -2^{62} ~ 2^{62}
        // value: N (1 ≤ N ≤ 100,000)
        Map<Long, Integer> map = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            long num = Long.parseLong(br.readLine());
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        br.close();

        long maxKey = -1, maxVal=0;
        for (Long i : map.keySet()) {
            int val = map.get(i);
            if(val>maxVal){
                maxKey=i;
                maxVal=val;
            } else if (val==maxVal && maxKey>i) {
                maxKey=i;
            }
        }
        System.out.println(maxKey);
    }
}
