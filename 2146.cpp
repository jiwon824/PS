#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>

#define MAX 101
using namespace std;

struct coordinate{
    int y, x;
};

int map[MAX][MAX];
int N =0;
int ans =2e9; //1e9=1*10^9, 2e9=2*10^9 특히, 2e9는 int 범위내에서 무한대 값을 나타내기 위해 사용하는 경우가 많다.
vector<coordinate> v; // 섬의 모서리를 넣을 벡터

// 우, 하, 좌, 상
// https://ldgeao99.tistory.com/400
// (-1, -1) (-1, 0) (-1, 1)
// (0, -1)   (0, 0)  (0, 1)
// (1, -1)   (1, 0)  (1, 1)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

void input();
void land_label(int y, int x, int label);
void distance();
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    distance();
    cout << ans << "\n";
    return 0;
}

void input(){
    // 이 나라는 N×N크기의 이차원 평면상에 존재한다.
    // 첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
    cin >> N;
    // 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.
    // 항상 두 개 이상의 섬(동서남북으로 육지가 붙어있는 덩어리)이 있는 데이터만 입력으로 주어진다.
    for(int i=0;i<N;i++){
        for (int j=0; j<N; j++){
            cin >> map[i][j];
            // 1로 입력되는 땅을 -1로 넣어준다(섬 라벨링을 위해)
            if (map[i][j]!=0) map[i][j] = -1;
        }
    }

    // 섬에 번호를 붙여주는 작업
    int label = 1;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (map[i][j]<0){
                land_label(i, j, label++);
            }
        }
    }

}


void land_label(int y, int x, int label){
    queue<coordinate> q;
    q.push({y, x});
    while (!q.empty()){
        bool edge = false;

        // 좌표를 변수에 저장
        int y = q.front().y;
        int x = q.front().x;
        map[y][x]=label;
        q.pop();

        // 4방향으로 탐색
        for (int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];

            // 이동할 좌표가 지도를 벗어나면 무시하기
            if (nx<0 || ny<0 || nx>N || ny>N) continue;
            // 아까 입력받을 때 섬들은 -1로 초기화 해줬음
            // 다음에 밟을 땅이 섬이라면
            if (map[ny][nx]<0){
                map[ny][nx] = label;
                q.push({ny,nx});
            }
            // 다음에 밟을 땅이 바다라면 지금 좌표는 바다와 육지의 경계 edge
            else if (map[ny][nx]==0) edge=true;
        }
        if (edge) v.push_back({y, x});
    }
}

// 섬의 모서리 -> 다른 섬의 모서리까지의 거리 중 최소값을 계산
// 라벨링할 때 벡터에 모서리 좌표를 넣어준 것을 이용한다.
void distance(){
    int tmp=0;
    // 왜 v.size()-1까지 반복하는 거지
    for(int i=0; i<v.size()-1; i++){
        int y=v[i].y;
        int x=v[i].x;
        // 여기는 왜 i+1부터 시작하고, v.size()까지 반복하는 거지
        for (int j=i+1;j<v.size();j++){
            int ny=v[j].y;
            int nx=v[j].x;

            // map[y][x]가 섬이고 && map[ny][nx]도 섬이면서 && 두 섬이 다른 섬일 경우
            if (map[y][x]>0 && map[ny][nx]>0 && map[y][x]!=map[ny][nx]){
                // 최단거리를 구하는 공식: (절대값)세로의 길이차 +(절대값)가로의 길이차 -1(겹치는 부분)
                tmp = abs(y-ny)+abs(x-nx)-1;
                // 계속 tmp 계산하면서 가장 작은 tmp값을 정답으로 저장
                if(ans>tmp) ans = tmp;
            }
        }
    }
}