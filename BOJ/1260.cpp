#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

int map[MAX][MAX];
bool visited[MAX];

// v 방문
void DFS(int v, int N);
void BFS(int v, int N);
int main(){
    // 첫 째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000),
    // 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
    int N, M, V;
    cin >> N >> M >> V;
    // 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
    // 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    // DFS
    // visited 배열 0으로 초기화
    fill_n(visited, N+1, 0);
    DFS(V, N);

    cout << '\n';
    
    // BFS
    // visited 배열 0으로 초기화
    fill_n(visited, N+1, 0);
    BFS(V, N);

    return 0;
}

// DFS는 stack을 이용하거나 재귀적으로 구현할 수 있음.
void DFS(int v, int N){
    visited[v] =1; // 방문했음 체크
    cout << v << " ";
    // N보다 같거나 작을때까지 반복해야 마지막 N번째 숫자까지 출력된다.
    for (int i=1; i<=N; i++){
        // 현재 정점과 이어져 있으면서 방문하지 않은 노드
        if(map[v][i]==1 && visited[i]==0){
            DFS(i, N);
        }
    }

}

// BFS는 queue를 사용해서 구현하는 것이 일반적인 것 같다.
void BFS(int v, int N){
    queue<int> q;
    q.push(v);
    visited[v] =1; // 방문했음 체크
    while(!q.empty()){
        v=q.front();
        q.pop();
        cout << v << " "; // 방문했으니까 출력
        // N보다 같거나 작을때까지 반복해야 마지막 N번째 숫자까지 출력된다.
        for (int i=1; i<=N; i++){
            // 현재 정점과 이어져 있으면서 방문하지 않은 노드
            if(map[v][i]==1 && visited[i]==0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
