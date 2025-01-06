import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Coord {
        int x, y;

        public Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int n, m;
    public static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력 처리
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = row.charAt(j) - '0';
            }
        }
        br.close();

        System.out.println(bfs());
    }

    public static int bfs() {
        // 방향 배열
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        Queue<Coord> queue = new ArrayDeque<>();
        int[][] cnt = new int[n][m];

        for (int[] row : cnt) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        queue.offer(new Coord(0, 0));
        cnt[0][0] = 0;

        while (!queue.isEmpty()) {
            Coord curr = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = curr.x + dx[dir];
                int ny = curr.y + dy[dir];

                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                int newCnt = cnt[curr.x][curr.y] + map[nx][ny];
                if (newCnt < cnt[nx][ny]) {
                    cnt[nx][ny] = newCnt;
                    queue.offer(new Coord(nx, ny));
                }
            }
        }
        return cnt[n - 1][m - 1];
    }
}
