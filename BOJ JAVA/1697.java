import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int k;
    public static boolean[] visited = new boolean[100_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        br.close();

        System.out.println(bfs());
    }

    public static int bfs(){
        // pos: number, second:time
        Queue<Pair> queue = new ArrayDeque<>();

        queue.offer(new Pair(n, 0));
        visited[n] = true;

        while(!queue.isEmpty()){
            Pair curr = queue.poll();

            // 동생이 있는 지점에 도착했다면 time 갱신
            if(curr.pos == k){
                return curr.time;
            }

            int[] next = {curr.pos - 1, curr.pos + 1, curr.pos * 2};
            for (int nextPos : next) {
                // 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다
                if(nextPos<0 || nextPos>100_000 || visited[nextPos]) continue;

                queue.offer(new Pair(nextPos, curr.time+1));
                visited[nextPos]=true;
            }
        }

        return -1;
    }

    public static class Pair{
        int pos;
        int time;

        public Pair(int first, int time) {
            this.pos = first;
            this.time = time;
        }
    }
}
