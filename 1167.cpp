// https://donggoolosori.github.io/2020/10/12/boj-1167/
#include <iostream>
#include <vector>
#include <cstring> // memset

#define MAX 100001
using namespace std;

struct Node
{
    int index;
    int dist;
};

int V;
vector<Node> graph[MAX];
bool visited[MAX];
int maxDist, maxNode; // maxNode에서 DFS를 한 번 더 해서 가장 먼 곳에 있는 노드까지의 거리가 maxDist가 된다

void DFS(int node, int dist);
int main(){
    // 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)
    cin >> V;

    int fr, to, dist;
    // 둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.
    // 정점 a의 번호 {정점 b의 번호 a에서 b 정점까지의 거리} {정점 b의 번호 a에서 b 정점까지의 거리} -1
    for (int i=0; i<V; i++){
        // cin >> 정점 a의 번호
        cin >> fr;
        // 입력이 -1이 아닐 동안 {정점 b의 번호 >> a에서 b 정점까지의 거리}
        while(1){
            cin >> to;
            // -1이 입력으로 들어오면 입력 종료
            if (to==-1) break;
            cin >> dist;
            // 부모-자식 순으로 입력되는 것이 아니기 때문에 양방향으로 저장
            graph[fr].push_back({to, dist});
            graph[to].push_back({fr, dist});
        }
    }

    // 트리의 가장 바깥에 있는 정점 찾기
    DFS(1, 0);
    // 초기화
    memset(visited, 0, sizeof(visited));
    maxDist = 0;

    // 가장 바깥에 있는 정점에서 가장 먼 거리에 있는 정점이 트리의 지름이 된다
    DFS(maxNode, 0);

    cout << maxDist << '\n';

    return 0;
}

void DFS(int node, int dist){
    // 방문한 노드는 무시
    if (visited[node]) return;

    visited[node]=true; // 방문했음 체크
    // maxDist값이 항상 최대값이 되도록 갱신
    if (maxDist<dist){
        maxNode=node; // node에서 가장 긴 거리에 있는 노드를 maxNode에 저장
        maxDist=dist; // 그 노드까지의 거리를 maxDist에 저장
    }
    
    // 현재 노드에 연결된 정점들로 dfs 수행
    for (int i=0; i<graph[node].size(); i++){
        int nextIdx=graph[node][i].index;
        int nextDist=graph[node][i].dist;
        // 다음 노드로 이동, 현재 길이+다음 노드까지의 길이
        DFS(nextIdx, nextDist+dist);
    }
    
}