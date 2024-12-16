import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX_N = 1000;

    public static List<List<Integer>> edges = new ArrayList<>(MAX_N+1);
    public static boolean[] visited = new boolean[MAX_N+1];


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [input]
        // 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2)
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // [init]
        // 각 인덱스에 대해 빈 리스트를 추가
        for (int i = 0; i <= n; i++) {
            edges.add(new ArrayList<>());
        }

        // 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            // 방향 없는 그래프
            edges.get(a).add(b);
            edges.get(b).add(a);
        }
        br.close();

        // [solution]
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            // 방문한 노드 건너뛰기
            if(visited[i]) continue;
            DFS(i);
            answer++;
        }
        // [output]
        System.out.println(answer);
    }

    public static void DFS(int v){
        if(visited[v]) return;
        visited[v]=true;

        for (int i = 0; i < edges.get(v).size(); i++) {
            int node = edges.get(v).get(i);
            if(visited[node]) continue;
            DFS(node);
        }
    }

}
