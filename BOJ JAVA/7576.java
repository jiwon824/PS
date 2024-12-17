import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int m;

    public static int[][] tomatoes;
    public static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다.
        // M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다.
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        //init
        tomatoes = new int[n][m];
        visited = new boolean[n][m];

        // 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다.
        // 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
            // 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다.
            // 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
        //토마토가 하나 이상 있는 경우만 입력으로 주어진다.
        for (int i = 0; i < n; i++) {
            st= new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                tomatoes[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        br.close();

        // [solution]
        int answer = BFS();

        // 안익었는데, 방문하지 않은 토마토가 있다면 -1
        boolean isPossible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(tomatoes[i][j]==0 && !visited[i][j]) {
                    answer=-1;
                    isPossible = false;
                    break;
                }
            }
            if(!isPossible) break;
        }
        // [output] 토마토가 모두 익을 때까지의 최소 날짜를 출력
        // 저장될 때부터 모든 토마토가 익어있는 상태이면 0, 토마토가 모두 익지는 못하는 상황이면 -1을 출력
        System.out.println(answer);
    }

    public static boolean CanGo(int x, int y){
        // 범위를 범어난 접근
        if(x<0 || x>= n || y<0 || y>=m) return false;
        // 이미 방문한 곳 || 바다
        if(visited[x][y] || tomatoes[x][y]==-1) return false;

        return true;
    }
    
    public static int BFS(){
        // 4방향
        // 상 하 좌 우
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int maxDay = 0;
        Queue<Tomato> queue = new ArrayDeque<>();

        // 익은 토마토 찾아서 전부 queue에 넣기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(tomatoes[i][j]==1){
                    queue.offer(new Tomato(i, j, 0));
                    visited[i][j]=true;
                }
            }
        }

        // queue가 빌 때까지 익은 토마토 근처 탐색
        while(!queue.isEmpty()){
            Tomato curr = queue.poll();
            maxDay = Math.max(maxDay, curr.day);
            for (int dir = 0; dir < 4; dir++) {
                int nx = curr.x +dx[dir];
                int ny = curr.y +dy[dir];
                if(CanGo(nx, ny)){
                    visited[nx][ny] =true;
                    queue.offer(new Tomato(nx, ny, curr.day+1));
                }
            }
        }

        return maxDay;
    }

    public static class Tomato {
        int x;
        int y;
        int day;

        public Tomato(int x, int y, int day) {
            this.x = x;
            this.y = y;
            this.day = day;
        }
    }
}
