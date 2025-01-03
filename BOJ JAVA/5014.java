import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static class Pair{
        int floor;
        int cnt;

        public Pair(int floor, int cnt) {
            this.floor = floor;
            this.cnt = cnt;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 첫째 줄에 F, S, G, U, D가 주어진다. (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000)
        StringTokenizer st = new StringTokenizer(br.readLine());
        int f = Integer.parseInt(st.nextToken()); // 건물은 1층부터 시작하고, 가장 높은 층은 F층
        int s = Integer.parseInt(st.nextToken()); // 강호가 지금 있는 곳은 S층
        int g = Integer.parseInt(st.nextToken()); // 스타트링크(=목적지)가 있는 곳의 위치는 G층
        // (만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)
        int u = Integer.parseInt(st.nextToken()); // U버튼은 위로 U층을 가는 버튼(+U)
        int d = Integer.parseInt(st.nextToken()); // D버튼은 아래로 D층을 가는 버튼(-D)
        br.close();

        // 강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오.
        int cnt = bfs(s, g, f, u, d);
        // 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력
        System.out.println((cnt==-1) ? "use the stairs" : cnt);
    }

    public static int bfs(int start, int target, int maxFloor, int up, int down){
        Queue<Pair> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[maxFloor+1];

        queue.offer(new Pair(start, 0));
        visited[start]=true;

        while (!queue.isEmpty()){
            Pair curr = queue.poll();
            // [return1] 목표 층에 도착했다면 cnt 반환
            if(curr.floor == target){
                return curr.cnt;
            }

            int[] nextFloor = {curr.floor+up, curr.floor-down};

            for (int next : nextFloor) {
                // 범위를 벗어난 층 || 이미 방문한
                if(next>maxFloor || next<=0 || visited[next]) continue;

                queue.offer(new Pair(next, curr.cnt+1));
                visited[next]=true;
            }

        }

        // [return2] 목표층에 도달할 수 없음
        return -1;
    }
}
