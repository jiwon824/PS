#include <iostream>
#include <cstring>

// w와 h는 50보다 작거나 같은 양의 정수이다.
#define MAX 51
using namespace std;

int w, h;
int NumberOfLand = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];

// 한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.
// https://ldgeao99.tistory.com/400
// (-1, -1) (-1, 0) (-1, 1)
// (0, -1)   (0, 0)  (0, 1)
// (1, -1)   (1, 0)  (1, 1)
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 좌, 좌상, 상, 우상, 우, 우하, 하, 좌하
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 좌, 좌상, 상, 우상, 우, 우하, 하, 좌하

void DFS(int y, int x);
int main(){
    while(1){
        // 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.
        cin >> w >> h;
        //w, h가 0이면 탈출
        if(!w && !h) break;

        // 초기화
        // https://taaewoo.tistory.com/9
        // memset()은 0, -1로만 초기화 할 수 있다.
            // (시작주소, 값, 크기) 2차원 배열도 쉽게 초기화 할 수 있음
            // <cstring> 헤더에 있음
        // fill()은 특정 값으로 초기화 할 수 있음
            // (시작주소, 끝주소, 값)
            // 2차원 배열의 경우 arr[50][50]이 존재할 때,
            // arr의 시작 주소를 나타내는 것은 arr[0]이고, 가장 마지막 주소는 arr[49][49]의 주소입니다.
            // 하지만 fill() 함수의 parameter 중 두 번째 parameter인 끝 주소는 범위에 포함시키지 않기 때문에,
            // arr[49][49]의 주소 +1을 해줘야 합니다. 그래서 결국 parameter에 넣어줘야 하는 값은 arr[50]
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        NumberOfLand = 0;

        // 둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
            // 이차원 배열
            // arr[0][0] arr[0][1] arr[0][2]
            // arr[1][0] arr[1][1] arr[1][2]
            // map[h][w]
                //w=3, h=2
                //1 1 1
                //1 1 1
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        // DFS
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                // 땅 있음+방문한 적 없는 땅
                if(map[i][j]==1&&visited[i][j]==0){
                    DFS(i, j);
                    NumberOfLand++;
                }
            }
        }
        cout << NumberOfLand << '\n';
    }    
    return 0;
}

void DFS(int y, int x){
    visited[y][x]=1; // 방문했음 체크
    for(int i=0;i<8;i++){
        //nx, ny는 nextX, nextY
        int nx = x+dx[i];
        int ny = y+dy[i];

        // x, y 범위가 w, h를 넘어가면 무시
        if(nx<0 || ny<0 || nx>w || ny>h) continue;
        // nx, ny 위치에 땅이 있으면서 방문한 적 없는 땅일 경우 DFS
        // 단지내 집 개수+=1
        if(map[ny][nx]==1 && visited[ny][nx]==0){
            DFS(ny, nx);
        }
    }
}