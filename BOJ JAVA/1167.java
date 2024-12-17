import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static List<List<EdgeInfo>> edges;
    public static int[] dist;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [input] 트리가 입력으로 주어진다.
        // 첫 번째 줄에서는 트리의 정점의 개수 V
        int v = Integer.parseInt(br.readLine());

        // init
        edges = new ArrayList<>(v+1);
        for (int i = 0; i <= v; i++) {
            edges.add(new ArrayList<>());
        }
        // 둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.
        // 정점 번호 연결된 간선의 정보(정점번호 그 정점까지의 거리) 주어지는 거리는 모두 10,000 이하의 자연수이다.
            // 예를 들어 네 번째 줄 "3 1 2 4 3 -1" 의 경우
            // 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고,
            // 정점 4와는 거리가 3인 간선으로 연결되어 있는 것
            // 각 줄의 마지막에는 -1이 입력으로 주어진다.
        for (int i = 0; i < v; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            while(true){
                int b = Integer.parseInt(st.nextToken());
                if(b == -1){
                    break;
                }
                int w = Integer.parseInt(st.nextToken());
                EdgeInfo edgeInfo = new EdgeInfo(b, w);
                edges.get(a).add(edgeInfo);
            }
        }
        br.close();

        // [solution]
        int farNode = findFarNode(1, v).node;
        int farDist = findFarNode(farNode, v).weight;

        // [output]
        System.out.println(farDist);
    }

    /**
     * @param start 시작 노드
     * @param v 노드의 총 갯수
     * @return {가장 먼 노드, dist}
     */
    public static EdgeInfo findFarNode(int start, int v){
        dist = new int[v+1];
        visited = new boolean[v+1];

        // start에서 시작, 시작 weight=0
        DFS(start, 0);

        int farNode =-1;
        int farDist = -1;
        for (int i = 1; i <= v; i++) {
            if(dist[i]>farDist){
                farNode = i;
                farDist = dist[i];
            }
        }
        return new EdgeInfo(farNode, farDist);
    }

    public static void DFS(int curr, int total){
        visited[curr] =true;
        // curr에 연결된 간선 확인
        for (EdgeInfo edgeInfo : edges.get(curr)) {
            int next = edgeInfo.node;
            int nDist = edgeInfo.weight;
            if(!visited[next]){
                dist[next]=total+ nDist;
                DFS(next, dist[next]);
            }
        }
    }

    public static class EdgeInfo{
        int node;
        int weight;

        public EdgeInfo(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

}
