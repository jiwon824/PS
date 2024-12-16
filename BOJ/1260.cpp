#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX_N 1000
using namespace std;

vector<vector<int> > edges(MAX_N+1);
bool visited[MAX_N+1] = {false, };

// v 방문
void DFS(int v);
void BFS(int v);
int main(){
    // [input]
    // 첫 째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000). 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
    int n, m, v;
    cin >> n >> m >> v;
    // 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
    // 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // 입력으로 주어지는 간선은 양방향이다.
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    // [solution]
    // 방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문
    for (int i = 1; i <= n; i++)
    {
        sort(edges[i].begin(), edges[i].end());
    }
    
    // DFS
    // visited 배열 0으로 초기화
    fill_n(visited, n+1, 0);
    DFS(v);

    cout << '\n';
    
    // BFS
    // visited 배열 0으로 초기화
    fill_n(visited, n+1, 0);
    BFS(v);

    return 0;
}

void DFS(int v){
    // 방문한 곳은 다시 탐색하지 않음
    if(visited[v]) return;
    visited[v]=true;
    cout << v << " ";

    // v에 연결된 노드 탐색
    for (int i = 0; i < edges[v].size(); i++)
    {
        DFS(edges[v][i]);
    }
    
}

void BFS(int v){
    queue<int> q;
    
    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (size_t i = 0; i < edges[node].size(); i++)
        {
            int connectedNode = edges[node][i];
            // 방문했으면 건너뛰기
            if(visited[connectedNode]) continue;

            q.push(connectedNode);
            visited[connectedNode]=true;
        }
        
    }
}