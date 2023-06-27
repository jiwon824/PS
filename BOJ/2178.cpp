#include <iostream>
#include <vector>
#include <utility>

#define MAX 101

using namespace std;

int N, M;
int** map;
bool** visited;
int ans = 10001; // 최대 100*100 배열이니까 최대 이동 수는 10000이 된다.

vector<pair<int, int>> dir;

void DFS(int x, int y, int depth);
void MakeDir();
int main() {
    // N×M크기의 배열로 표현되는 미로
    // 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
    // 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
    cin >> N >> M;
    map = new int* [N];
    visited = new bool* [N];

    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
        visited[i] = new bool[M];
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j]-'0'; // map 배열에 입력 숫자 넣기
            visited[i][j] = 0; // visited 배열 초기화
        }
    }
    MakeDir(); // 상하좌우 좌표 벡터에 입력

    
    // 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
    // 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
    // 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
    DFS(0, 0, 1);

    cout << ans << '\n';

    return 0;
}

void DFS(int x, int y, int depth) {
    // 목표지점(N, M)에 도착했으면 min값 갱신하고 DFS끝
    // (0, 0)에서 시작하니까 N-1, M-1이 (N, M)
    if (x == N-1 && y == M-1) {
        if (depth < ans) {
            ans = depth;
            //return;
        }
    }

    //cout << x << " "<< y << '\n';
    
    
    // 4방향(=dir.size())으로 탐색하면서 map[N][M]=1 && visited[N][M]=0 인 곳 방문하기
    for (int i = 0; i < dir.size(); i++) {
        int nextN = x + dir[i].first;
        int nextM = y + dir[i].second;
        //cout << nextN << " " << nextM << '\n';
        // 
        // 맵 벗어나면 탐색x
        if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) continue;
        
        if (map[nextN][nextM]==1 && visited[nextN][nextM]==0) {
            // cout << "h" << '\n';
            // 방문체크
            visited[x][y] = 1;
            DFS(nextN, nextM, depth + 1);
            visited[x][y] = 0;
        }
    }
    

}
void MakeDir() {
    dir.push_back(make_pair(-1, 0)); // 상
    dir.push_back(make_pair(1, 0)); //  하
    dir.push_back(make_pair(0, -1)); // 좌
    dir.push_back(make_pair(0, 1)); // 우
}