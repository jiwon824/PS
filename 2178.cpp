// (0, 0)에서 출발하여 (N-1, M-1)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램
#include <iostream>
#include <queue>

#define MAX 101
using namespace std;

struct coordinate{
    int x, y;
};

int N, M;
int map[MAX][MAX];
// 우, 하, 좌, 상
// https://ldgeao99.tistory.com/400
// (-1, -1) (-1, 0) (-1, 1)
// (0, -1)   (0, 0)  (0, 1)
// (1, -1)   (1, 0)  (1, 1)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };


queue<coordinate> q; // 좌표를 저장하는 큐


void BFS(int x, int y);
int main(){
    // 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
    cin >> N >> M;

    // 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
    // 이차원 배열
        // arr[0][0] arr[0][1] arr[0][2]
        // arr[1][0] arr[1][1] arr[1][2]
    // map[N][M]
    for (int i=0; i<N; i++){
        string MString;
        cin >> MString;
        for(int j=0; j<M; j++){
            map[i][j]= MString[j]-'0';
        }
    }

    BFS(0, 0);

    // 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.
    // 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
    cout << map[N-1][M-1] << '\n';
    return 0;
}
void BFS(int x, int y){
    q.push({x, y});
    while (!q.empty()){
        //visited[y][x] =1; // 방문했음 체크

        int x = q.front().x;
        int y = q.front().y;
        q.pop(); // x, y에 저장한 좌표 제거

        for (int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            // 이동할 좌표가 지도를 벗어나면 무시하기
            // map[N][M]
            if(nx<0 || ny<0 || nx>N || ny>M) continue;
            // 다음 좌표가 1이어야 이동할 수 있음
            if(map[nx][ny]==1){
                map[nx][ny]=map[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
}