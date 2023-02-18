// https://jdselectron.tistory.com/55
#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

// 구조체를 안 쓰고 이렇게 써도 된다.
// queue<pair<int,int>> q;
// q.push(make_pair(i, j));
struct tomato {
    int y, x;
};
 
queue<tomato> q;

int box[MAX][MAX];
int M, N, result=0;
// 우, 하, 좌, 상
// https://ldgeao99.tistory.com/400
// (-1, -1) (-1, 0) (-1, 1)
// (0, -1)   (0, 0)  (0, 1)
// (1, -1)   (1, 0)  (1, 1)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

// 함수
void BFS();
int main(){
    // 첫 줄에는 상자의 크기를 나타내는 두 정수 M,N(2 ≤ M,N ≤ 1,000)이 주어진다.
    // M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
    cin >> M >> N;

    // 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다.
    // 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
    // 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
    // 이차원 배열
        // arr[0][0] arr[0][1] arr[0][2]
        // arr[1][0] arr[1][1] arr[1][2]
    // box[N][M]
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> box[i][j];
            if (box[i][j] == 1) { // 익은토마토(1) -> 큐
                q.push({ i, j });
            }
        }
    }
    
    BFS();

    // 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다.
    // 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력
    // 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // 익지않은 토마토(0)가 존재할 경우
            if (box[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }

            // box에 저장된 일수 중 가장 큰 수를 result에 저장
            if (result < box[i][j]) {
                result = box[i][j];
            }
        }
    }
    cout << result-1 << '\n';
    return 0;
}

void BFS(){
    while (!q.empty()){
        // 큐의 현재 원소(익은 토마토(1))를 꺼내기
        // 큐가 구조체라서 .x, .y 이렇게 접근
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        // 해당 위치의 주변을 확인
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            //범위를 벗어나면 무시하기
                // box[N][M]
                // box[ny][nx]
            // nx>=M, ny>=N 인데 등호 없이 nx>M, ny>N라고 해서 틀림
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            // 범위를 벗어나지 않은 익지 않은 토마토
            if(box[ny][nx]==0){
                // nx, ny는 현재 위치(x, y)보다 1일 뒤에 숙성
                box[ny][nx]=box[y][x]+1;
                // 숙성되면 1이 되는 거니까 큐에 넣어줌
                q.push({ny, nx});
            }
        }
    }
}