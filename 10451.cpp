#include <iostream>

#define MAX 1001
using namespace std;

int arr[MAX];
bool visited[MAX];

// 방문할 노드 v, 정점의 개수 N
void DFS(int v, int N);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        // 초기화
        fill_n(arr, MAX, 0);
        fill_n(visited, MAX, 0);

        // 각 테스트 케이스의 첫째 줄에는 순열의 크기 N (2 ≤ N ≤ 1,000)이 주어진다.
        int N;
        cin >> N;
        for (int i=1; i<=N;i++){
            // 둘째 줄에는 순열이 주어지며, 각 정수는 공백으로 구분되어 있다.
            cin >> arr[i];
        }
        
        int cycle = 0;
        for (int i=1; i<=N; i++){
            // 연결된 그래프를 모두 방문한 후에, 방문하지 않은 노드가 있다면
            if(visited[i]==0){
                // 그 노드부터 시작하여 다시 DFS
                DFS(i, N);
                cycle++;
            }
        }
        cout << cycle << '\n';
    }
    return 0;
}

void DFS(int v, int N){
    visited[v]=1; // 방문했음 체크
    // N보다 같거나 작을때까지 반복해야 마지막 N번째 숫자까지 출력된다.
    for (int i=1; i<=N; i++){
        int next = arr[v];
        // 방문하지 않은 노드
        if(visited[next]==0){
            DFS(next, N);// 1에 3이 저장되어 있으면 3으로 가기
        }
    }
}