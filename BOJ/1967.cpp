#include <iostream>
#include <vector>
#include <cstring> // memset

#define MAX 10001
using namespace std;

struct Node
{
    int index;
    int dist;
};

int n;
vector<Node> graph[MAX];
bool visited[MAX];
int maxDist, maxNode; // maxNode에서 DFS를 한 번 더 해서 가장 먼 곳에 있는 노드까지의 거리가 maxDist가 된다

void DFS(int node, int dist);
int main(){
    // 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)
    cin >> n;

    // 둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다.
    for (int i=0; i<n-1; i++){
        // 간선에 대한 정보는 세 개의 정수로 이루어져 있다.
        // 부모 노드 >> 자식 노드 >> (1<=간선의 가중치<100)
        int parent, child, dist;
        cin >> parent >> child >> dist;
        graph[parent].push_back({child, dist});
        graph[child].push_back({parent, dist});
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
