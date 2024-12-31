import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int answer;
    public static int[] arr;
    public static boolean[] visited;
    public static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다.
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        visited = new boolean[n];

        // 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        br.close();

        backtracking();
        System.out.println(answer);
    }

    public static void backtracking(){
        if(stack.size()==n){
            answer = Math.max(answer, calculate());
            return;
        }

        for (int i = 0; i < n; i++) {
            if(visited[i]) continue;
            stack.push(arr[i]);
            visited[i] = true;

            backtracking();

            stack.pop();
            visited[i]=false;
        }
    }

    // |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
    public static int calculate(){
        int result = 0;
        int lhs, rhs;
        for (int i = 1; i < n; i++) {
            lhs = stack.get(i-1);
            rhs = stack.get(i);
            result += Math.abs(lhs-rhs);
        }
        return result;
    }
}
