import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int landNum = 1;
    public static int[][] map;
    public static boolean[][] visited;

    // 상 하 좌 우
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        // init
        map = new int[n+1][n+1];
        visited = new boolean[n+1][n+1];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        br.close();

        // 1. 섬 라벨링 하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(!visited[i][j] && map[i][j]!=0){
                    DFS(i, j);
                    landNum++;
                }
            }
        }


        // 2. 한 섬에서 다른 섬으로 가는 최단거리 찾기
        int answer = (int)1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 바다에서는 시작하지 않음
                if(map[i][j]==0) continue;

                // visited 초기화해주기
                visited = new boolean[n+1][n+1];
                int result = BFS(i, j);
                answer = (result==-1) ? answer : Math.min(answer, result);
            }
        }

        // [output]
        System.out.println(answer);
    }

    public static boolean CanGo(int x, int y){
        if(x<0 ||x>=n || y<0 || y>=n) return false;
        if(visited[x][y]) return false;

        return true;
    }


    // 섬 라벨링
    public static void DFS(int x, int y){
        if(visited[x][y]) return;

        visited[x][y]=true;
        map[x][y]=landNum;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // 갈 수 있는 곳(방문한 적x + 범위내) && 바다가 아니라면
            if(CanGo(nx, ny) && map[nx][ny]!=0){
                DFS(nx, ny);
            }
        }
    }

    // 다리 설치
    public static int BFS(int startX, int startY){
        int startLand = map[startX][startY]; // 현재 섬의 번호

        Queue<Coord> queue = new ArrayDeque<>();
        queue.offer(new Coord(startX, startY, 0));
        visited[startX][startY] = true;

        while(!queue.isEmpty()){
            Coord curr = queue.poll();

            // 다른 섬에 도착했으면 다리 갯수 반환(섬에 도착했을 때 cnt+1을 queue에 넣었으므로 1을 빼준다)
            if(map[curr.x][curr.y]!=0 && map[curr.x][curr.y]!= startLand){
                //System.out.println("("+startX+","+startY+") -> "
                //                    +"("+curr.x +","+curr.y+"): "+ (curr.cnt-1));
                return curr.cnt-1;
            }

            // 4방향 탐색
            for (int dir = 0; dir < 4; dir++) {
                int nx = curr.x +dx[dir];
                int ny = curr.y +dy[dir];
                if(CanGo(nx, ny) && map[nx][ny]!= startLand){
                    queue.offer(new Coord(nx, ny, curr.cnt+1));
                    visited[nx][ny]=true;
                }
            }
        }

        return -1;
    }

    public static class Coord{
        int x;
        int y;
        int cnt;

        public Coord(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}
