import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_1861 {

	public static int[] dx = { 0, 0, 1, -1 };
	public static int[] dy = { 1, -1, 0, 0 };

	public static int n;
	public static int[][] rooms;

	public static int maxLen;
	public static int minRoomNum;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			// 각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N (1 ≤ N ≤ 10^3)이 주어진다.
			n = Integer.parseInt(br.readLine());

			// 방에 적힌 숫자의 정보
			rooms = new int[n][n];
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					rooms[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			// init
			maxLen = 0;
			minRoomNum = n * n;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dfs(i, j, 1, rooms[i][j]);
				}
			}
			sb.append('#').append(tc).append(' ').append(minRoomNum).append(' ').append(maxLen).append('\n');
		}
		System.out.println(sb);
	}

	private static void dfs(int x, int y, int len, int startNum) {

		int currRoom = rooms[x][y];

		// 길이 갱신
		if (len > maxLen) {
			maxLen = len;
			minRoomNum = startNum;
		} else if (len == maxLen) {
			minRoomNum = Math.min(minRoomNum, startNum);
		}

		// 4방향으로 돌면서 갈 수 있는 방 가기
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 배열 범위 밖이거나 방문하지 않은 칸 재방문 금지
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			// 현재 방에 적힌 숫자보다 1 큰 방으로만 이동 가능
			if (rooms[nx][ny] == currRoom+1) {
				dfs(nx, ny, len + 1, startNum);
			}
		}

	}
}
