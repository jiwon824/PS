// https://jaimemin.tistory.com/655
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring> //memset

#define MAX 1001
using namespace std;

struct coordinate{
    int x, y;
};

int N, ans;
int map[MAX][MAX];
bool visited[MAX][MAX];
// 우, 하, 좌, 상
// https://ldgeao99.tistory.com/400
// (-1, -1) (-1, 0) (-1, 1)
// (0, -1)   (0, 0)  (0, 1)
// (1, -1)   (1, 0)  (1, 1)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };


// DFS로 섬에 번호를 붙여주는 작업 
void Make_LandLabel(int x, int y, int label);
// BFS로 최단 거리를 구함
int BFS(int label);
int main(){
    // 이 나라는 N×N크기의 이차원 평면상에 존재한다.
    // 첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
    cin >> N;
    // 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.
    // 항상 두 개 이상의 섬(동서남북으로 육지가 붙어있는 덩어리)이 있는 데이터만 입력으로 주어진다.
    for(int i=0;i<N;i++){
        for (int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    
    // 섬에 번호 붙여주기 -> 각 섬을 구분
    int label=1;
    for (int i=0;i<N;i++){
        for (int j=0; j<N; j++){
            // map[i][j]==1 && visited[i][j]==0
            if(map[i][j] && !visited[i][j]){
                // 다른 섬이 있는지 체크(있다면 다음 번호 붙여주기)
                Make_LandLabel(i, j, label++);
            }
        }
    }

    // 최단거리를 구해야해서 min을 써야 하니까 큰 수로 초기화 해줘야 함
    ans=987654321;
    // 각 섬에서 제일 가까운 섬까지의 최단거리 구하기
    for (int i=1; i<label; i++){
        // BFS해야 하니까 방문기록 초기화해주기
        memset(visited, 0, sizeof(visited));
        ans = min(ans, BFS(i));
    }
    cout << ans << '\n';
    
    return 0;
}

// DFS로 섬에 번호 붙여주기: BFS로 하는 방법도 있던데 그것도 나중에 해보기
void Make_LandLabel(int x, int y, int label){
    visited[x][y]=1;
    map[x][y]=label;

    // 상하좌우 살피면서 이 섬에 방문하지 않은 땅이 있는지 체크
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        // 범위를 벗어나면 무시하기
        if(nx<0||ny<0||nx>N||ny>N) continue;

        if (map[nx][ny] && !visited[nx][ny]){
            Make_LandLabel(nx, ny, label);
            label++;
        }
    }
}


int BFS(int label){
    queue<coordinate> q; // 좌표를 저장하는 큐
    
    // 일단 인자로 들어온 섬의 좌표를 다 큐에 넣는다
    for (int i=0; i<N; i++){
        for (int j=0;j<N;j++){
            if (map[i][j]==label){
                visited[i][j]=1; // 방문했음 체크
                q.push({i, j});
            }
        }
    }

    int shortCut=0; // 최단 거리를 저장하는 변수
    while (!q.empty()){
        int s = q.size();
        for (int i=0; i<s; i++){
            // 큐의 맨 앞에 있는 좌표를 변수에 저장하고 큐에서 삭제
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            
            // 4방향으로 탐색하기
            for (int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                // 범위를 벗어나면 무시하기
                if(nx<0||ny<0||nx>N||ny>N) continue;
                // 바다도 아니고, 현재 섬도 아니라면(==다른 섬에 도착했으면 shortCut 반환)
                if (map[nx][ny]!=0 && map[nx][ny]!=label) return shortCut;
                // 방문하지 않은 바다라면 큐에 넣어주기
                else if (map[nx][ny]==0 && visited[nx][ny]==0){
                    visited[nx][ny]=1; // 방문했음 체크
                    q.push({nx, ny});
                }
            }
        }
        shortCut++;
    }
}