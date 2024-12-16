import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력: 7 3
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        br.close();

        // arr 초기화
        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        // 출력: <3, 6, 2, 7, 5, 1, 4>
        StringBuilder sb = new StringBuilder();
        int curr = 0;

        sb.append('<');
        while (!arr.isEmpty()) {
            curr = (curr + k - 1) % arr.size();
            int num = arr.get(curr);
            if(arr.size()>1){
                sb.append(num).append(", ");
            } else{
                sb.append(num).append('>');
            }
            arr.remove(curr);
        }
        System.out.println(sb);
    }
}
