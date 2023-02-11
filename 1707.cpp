#include <iostream>
#include <vector>

#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

vector<int> map[MAX];
int color[MAX];

// 이분 그래프인지 검사할 함수
bool isBipartiteGraph(int V);
// 방문할 노드 v, 정점의 개수 N
void DFS(int v, int N);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 입력은 여러 개의 테스트 케이스로 구성되어 있는데,
    // 첫째 줄에 테스트 케이스의 개수 K(2 ≤ K ≤ 5)가 주어진다.
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        // 각 테스트 케이스의 첫째 줄에는
        // 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다.
        // 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다.
        int V, E;
        cin >> V >> E; //(1 ≤ V ≤ 20,000), (1 ≤ E ≤ 200,000)

        // map, color 초기화
        for (int i=0; i<=V; i++){
            map[i].clear();
        }
        fill_n(color, MAX, 0);

        // +++ 간선으로 이어진 노드들 체크하기 +++
        // 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데,
        // 각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다. 
        for (int e=0;e<E;e++){
            int u, v;
            cin >> u >> v;
            map[u].push_back(v);
            map[v].push_back(u);
        }

        // +++ 빨강 파랑 칠하면서 이분그래프 검사 +++
        for (int i=1; i<=V; i++){
            // 연결된 그래프를 모두 방문한 후에, 방문하지 않은 노드가 있다면
            if(color[i]==0){
                // 그 노드부터 시작하여 다시 DFS
                DFS(i, V);
            }
        }

        //이분 그래프면 YES, 아니면 NO 출력
        if(isBipartiteGraph(V)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}

// 정점의 개수 N
bool isBipartiteGraph(int V){
    // 모든 정점을 돌면서 인접한 정점과 색이 같은지 확인해야함
    for(int cur=1; cur<=V; cur++){
        // 연결된 게 자기자신 뿐일 경우엔 size가 0이라서 돌아가지 않는다.
        // map이 vector였으면 map[cur].size()라고 하면 되는데, 배열이라서 sizeof를 써줘야 한다.
        int mapSize = map[cur].size();
        for (int i=0; i<mapSize; i++){
            int next = map[cur][i];
            // 현재 정점과 인접한 정점이 색이 같다면 이분 그래프 아님
            if(color[cur] == color[next]) return false;
        }
    }
    return true;
}

// 방문할 노드 v, 정점의 개수 N
void DFS(int v, int N){
    // 방문하지 않았던 노드는 빨간색으로 칠하기
    if (color[v]==0) color[v] = RED; 

    int mapSize = map[v].size();
    // N보다 같거나 작을때까지 반복해야 마지막 N번째 숫자까지 출력된다.
    for (int i=0; i<mapSize; i++){
        int next = map[v][i];
        // 방문하지 않은 노드
        if(color[next]==0){
            // 현재 노드가 빨강이면 파랑, 파랑이면 빨강 칠하기
            if(color[v]==RED) color[next]=BLUE;
            else if (color[v]==BLUE) color[next]=RED;
            DFS(next, N);
        }
    }
}
