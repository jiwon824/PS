import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static final int MAX_N = 25;

    public static int n;
    public static String[] map = new String[MAX_N];
    public static boolean[][] visited = new boolean[MAX_N][MAX_N];
    
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [input]
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            map[i]=br.readLine();
        }
        br.close();

        // [solution]
        // 상(-1, 0) 하(1, 0) 좌(0, -1) 우(0, 1)
        List<Integer> complexes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = map[i].charAt(j);
                if(!visited[i][j] && c-'0'==1) {
                    int numOfHouse = BFS(i, j);
                    complexes.add(numOfHouse);
                }
            }
        }
        // 오름차순 정렬
        Collections.sort(complexes);

        // [output]
        StringBuilder sb = new StringBuilder();
        // 첫 번째 줄에는 총 단지수를 출력
        sb.append(complexes.size()).append('\n');
        // 다음 줄부터는 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력
        for (Integer e : complexes) {
            sb.append(e).append('\n');
        }
        System.out.println(sb);
    }

    public static class MyCoord {
        int x;
        int y;

        public MyCoord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static boolean CanGo(int x, int y){
        // 범위를 벗어난 접근 ArrayIndexOutOfBoundsException
        if(x<0 || x>=n || y<0 || y>=n) return false;
        // 방문한 장소 || 집이 없음
        if(visited[x][y] || map[x].charAt(y)-'0'!=1) return false;

        return true;
    }

    public static int BFS(int startX, int startY){
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        Queue<MyCoord> queue = new ArrayDeque<>();

        // 현재 좌표를 queue에 넣기
        MyCoord start = new MyCoord(startX, startY);
        queue.offer(start);

        // 현재좌표 방문 체크
        visited[startX][startY]=true;
        int numOfHouse=1;

        while(!queue.isEmpty()){
            MyCoord curr = queue.poll();
            for (int dir = 0; dir < 4; dir++) {
                int nx = curr.x+dx[dir];
                int ny = curr.y+dy[dir];

                // 방문하지 않았으면서 집이 있으면
                if(CanGo(nx, ny)){
                    visited[nx][ny]=true; // 방문 체크
                    MyCoord next = new MyCoord(nx, ny);
                    queue.offer(next); // queue에 등록
                    numOfHouse++; // 집 갯수 증가
                }
            }
        }

        return numOfHouse;
    }

}
