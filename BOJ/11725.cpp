#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int N; // 노드의 개수 N (2 ≤ N ≤ 100,000)
int parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];

void DFS(int node);
int main(){
    // 첫째 줄에 노드의 개수 N이 주어진다.
    cin >> N;
    // 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
    for (int i=0; i<N-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        // 주어진 노드들이 부모 - 자식 순서가 아니라 랜덤으로 주어지기 때문에 양방향으로 넣어줘야합니다.
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);

    }
    // 1은 무조건 루트이기 때문에 1부터 넣고 방문했다고 표시한 뒤 DFS
    DFS(1);
/*
    cout << "parent 배열에 저장된 수 확인" << '\n';
    for (int i=0;i<=N;i++){
        cout << parent[i]<< " ";
    }
*/
    for (int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
    
    return 0;
}

void DFS(int node){
    //cout << "++++++++++ DFS(" << node <<") 시작 ++++++++++" << '\n';
    visited[node]=1; // 방문했음 표시
    // 하나의 루트에 여러 개의 자식이 달려있을 수 있으니까 vector[node]에 달린 자식들을 하나씩 봐줌
    for (int i=0; i<tree[node].size(); i++){
        int next = tree[node][i];
        //cout << "다음 탐색 노드는 tree[" << node << "][" << i << "]: " << next << '\n';
        // 아직 방문 전이라면
        if (!visited[next]){
            // next의 parent는 node라고 parent[] array에 저장해주기
            //cout << "parent[" << next << "]에 " << node << "저장" << '\n';
            parent[next]=node;
            DFS(next);
        }
        //else cout << next << "번 노드는 이미 방문한 노드" << '\n';
    }
    //cout << "++++++++++ DFS(" << node <<") 끝 ++++++++++" << '\n';
}
