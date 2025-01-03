import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Square{
        int x1, y1, x2, y2;

        public Square(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    public static int n;
    public static int[] uf;
    public static Square[] squares;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫째 줄에 직사각형의 개수 N이 주어진다. (1 ≤ N ≤ 1000)
        int n = Integer.parseInt(br.readLine());

        // union-find 배열 초기화
        uf = new int[n+1];
        for (int i = 0; i <= n; i++) {
            uf[i] = i;
        }

        // 다음 N개의 줄에는 직사각형의 좌표 x1, y1, x2, y2가 주어진다. (−500 ≤ x1 < x2 ≤ 500), (−500 ≤ y1 < y2 ≤ 500)
        // (x1, y1)는 직사각형의 한 꼭짓점 좌표이고, (x2, y2)는 그 점의 대각선 방향의 반대 꼭짓점의 좌표이다.
        squares = new Square[n+1];
        // 연필을 내리면 움직일 때 화면에 선을 그리고, 올리면 선을 그리지 않고 그냥 지나가기만 한다.
        // 제일 처음에 거북이는 (0,0)에 있고, 거북이가 보고 있는 방향은 y축이 증가하는 방향이다. 또한 연필은 내리고 있다.
        squares[0]= new Square(0, 0, 0, 0);
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            squares[i] = new Square(x1, y1, x2, y2);
        }
        br.close();

        // 연결되어 있다면 union으로 같은 그룹 체크
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if(isConnected(squares[i], squares[j])){
                    union(i, j);
                }
            }
        }

        // N개의 직사각형을 그리는 필요한 PU명령의 최솟값을 출력
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i <= n; i++) {
            set.add(find(i));
        }
        System.out.println(set.size()-1);
    }

    // 두 사각형이 만나는 점이 있는지 체크하기
    public static boolean isConnected(Square a, Square b) {
        // 상하로 떨어진 경우
        if (a.x2 < b.x1 || b.x2 < a.x1) return false;
        // 좌우로 떨어진 경우
        if (a.y2 < b.y1 || b.y2 < a.y1) return false;

        // a 안에 b가 있음
        if(a.x1<b.x1 && a.y1<b.y1 && a.x2> b.x2 && a.y2 > b.y2) return false;
        // b 안에 a가 있음
        if(b.x1<a.x1 && b.y1<a.y1 && b.x2 > a.x2 && b.y2 > a.y2) return false;

        return true;
    }

    public static int find(int x){
        if(uf[x]==x) return x;
        return uf[x] = find(uf[x]);
    }

    public static void union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            uf[rootX]=rootY;
        }
    }

}
