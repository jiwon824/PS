#include <iostream>

#define MAX 1001
using namespace std;

int map[MAX][MAX];
bool visited[MAX];

void DFS(int v, int N);
int main(){
    // 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
    int N, M;
    cin >> N >> M;
    // 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v)
    // 같은 간선은 한 번만 주어진다.
    for (int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
    int connectedComponent = 0;
    for (int i=1; i<=N; i++){
        // 연결된 그래프를 모두 방문한 후에, 방문하지 않은 노드가 있다면
        if(visited[i]==0){
            // 그 노드부터 시작하여 다시 DFS
            DFS(i, N);
            connectedComponent++;
        }
    }
    cout << connectedComponent << '\n';
    return 0;
}

void DFS(int v, int N){
    visited[v] =1; // 방문했음 체크
    // N보다 같거나 작을때까지 반복해야 마지막 N번째 숫자까지 출력된다.
    for (int i=1; i<=N; i++){
        // 현재 정점과 이어져 있으면서 방문하지 않은 노드
        if(map[v][i]==1 && visited[i]==0){
            DFS(i, N);
        }
    }
}
