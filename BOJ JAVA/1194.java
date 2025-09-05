import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static class Coord {
		int x;
		int y;
		int dist;
		int key;

		public Coord(int x, int y, int dist, int key) {
			this.x = x;
			this.y = y;
			this.dist = dist;
			this.key = key;
		}
	}

	public static int[] dx = { 0, 0, 1, -1 };
	public static int[] dy = { 1, -1, 0, 0 };

	public static int n, m; // 세로 크기 n, 가로 크기 m

	public static char[][] map; // 입력배열
	public static boolean[][][] visited; // [x][y][key]

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// [input] n, m 입력 받기
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		// [input] map 입력 받기
		map = new char[n][m]; // init map
		int startX = -1, startY = -1; // 시작 지점

		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == '0') {
					startX = i;
					startY = j;
				}
			}
		}

		// [solution] bfs 할 거임(최소 이동 횟수==최단거리==bfs)
		visited = new boolean[n][m][64]; // [x][y][fedcba 열쇠 소유 여부] 6개이므로 2^6 = 64
		int minDist = bfs(startX, startY);
		System.out.println(minDist);

	}

	private static int bfs(int startX, int startY) {
		Queue<Coord> queue = new ArrayDeque<>();

		// 시작점 넣어주기 + 방문 예약
		// x, y, dist(시작할 때는 이동횟수0), key(시작할 때 아무것도 없으니까 000000(2) = 0(10))
		queue.offer(new Coord(startX, startY, 0, 0));
		visited[startX][startY][0] = true;

		// 이제 탐색 시작할 거임
		while (!queue.isEmpty()) {
			Coord curr = queue.poll();

			// [return] 도착 지점을 찾음
			if (map[curr.x][curr.y] == '1') {
				return curr.dist;
			}

			// curr 주위 진짜 진짜 탐색할 거임
			for (int dir = 0; dir < 4; dir++) {
				int nx = curr.x + dx[dir];
				int ny = curr.y + dy[dir];
				
				int nd = curr.dist+1;
				int nk = curr.key;
				
				// 배열 범위를 벗어난 접근 || 벽은 못지나감
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#') {
					continue;
				}

				// [key값 갱신]
				if('A'<=map[nx][ny] && map[nx][ny]<='Z') { // 문 (A~Z)
					// 열쇠가 없으면 continue;
					if((nk & (1 << (map[nx][ny]-'A'))) == 0) {
						continue;
					}
				} else if('a'<=map[nx][ny] && map[nx][ny]<='z') { // 열쇠인 경우(a~z)
					nk |= (1 << (map[nx][ny]-'a'));
				}
				
				// 방문 한 곳은 다시 가면 안 됨(nk를 구해야 해서 방문 체크를 여기서 진행)
				if(visited[nx][ny][nk]) {
					continue;
				}
				
				// [방문 예약] 나머지 방문 안 한 좌표 중 열쇠가 있는 문, 열쇠, '.' 으로는 모두 이동 가능
				queue.offer(new Coord(nx, ny, nd, nk));
				visited[nx][ny][nk] = true;
			}

		}

		// [return] 여기로 나왔으면 도착지점 못 찾은 거 -1 반환
		return -1;
	}
}
