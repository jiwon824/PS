import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    // 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데,
    public static int[] dx = {0, 0, -1, 1};
    public static int[] dy = {-1, 1, 0, 0};

    public static int r;
    public static int c;

    public static int answer = 0;
    public static char[][] board;
    public static boolean[][] visited;
    public static List<Character> visitedChars = new ArrayList<>(); // 방문했던 알파벳 기록

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 세로 R칸, 가로 C칸으로 된 표 모양의 보드
        // 첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20)
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        board = new char[r + 1][c + 1];
        visited = new boolean[r + 1][c + 1];

        // 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.
        for (int i = 0; i < r; i++) {
            String row = br.readLine();
            for (int j = 0; j < c; j++) {
                board[i][j] = row.charAt(j);
            }
        }
        br.close();

        // 좌측 상단(board[0][0])에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램
        // 말이 지나는 칸은 좌측 상단의 칸도 갯수에 포함된다.
        visited[0][0]=true;
        visitedChars.add(board[0][0]);
        dfs(0, 0, 1);

        System.out.println(answer);
    }

    public static void dfs(int x, int y, int cnt) {
        answer = Math.max(answer, cnt);

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 1. 배열 범위를 벗어나는 경우
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 2. 같은 알파벳이 적힌 칸을 두 번 지날 수 없다. || 이미 방문했던 칸
            if (visitedChars.contains(board[nx][ny]) || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            visitedChars.add(board[nx][ny]);
            dfs(nx, ny, cnt+1);
            visited[nx][ny]=false;
            visitedChars.remove(visitedChars.size()-1);

        }
    }

}
