#include <iostream>

#define MAX 100010
using namespace std;

int arr[MAX];
bool visited[MAX];
bool done[MAX]; //방문이 끝났는지 여부
int teamStu=0;

void DFS(int v, int n);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
    int T;
    cin >> T;
    for (int i=0; i<T;i++){
        // 초기화
        fill_n(arr, MAX, 0);
        fill_n(visited, MAX, 0);
        fill_n(done, MAX, 0);
        teamStu = 0;

        // 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다.
        int n;
        cin >> n;

        // 각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다.
        // *** 모든 학생들은 1부터 n까지 번호가 부여된다. ***
        for(int j=1;j<=n;j++){
            cin >> arr[j];
        }

        // 팀 편성
        for (int j=1; j<=n; j++){
            // 연결된 그래프를 모두 방문한 후에, 방문하지 않은 노드가 있다면
            if(visited[j]==0){
                // 그 노드부터 시작하여 다시 DFS
                DFS(j, n);
            }
        }
        // 어느 팀에도 속하지 않는 학생의 수
        cout << n-teamStu << '\n';
    }
    return 0;
}

void DFS(int v, int n){
    visited[v]=1; // 방문했음 체크

    // 다음에 방문할 노드
    int next = arr[v];
    // 방문할 노드가 아직 한 번도 방문하지 않은 노드라면
    if(visited[next]==0){
        DFS(next, n);// 1에 3이 저장되어 있으면 3으로 가기
    }
    // 방문했던 노드인데, 방문이 끝난 노드가 아니라면
    // visited[next]==1 && done[next]==0
    else if(done[next]==0){
        // 팀원을 모두 센다
        for (int i=next;i!=v;i=arr[i]){
            teamStu++;
        }
        teamStu++; // 자기자신도 센다
    }
    done[v] = 1; // 더이상 노드를 방문할 일 없음
}
