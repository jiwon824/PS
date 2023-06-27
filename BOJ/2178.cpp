#include <iostream>
#include <vector>
#include <utility>

#define MAX 101

using namespace std;

int N, M;
int** map;
bool** visited;
int ans = 10001; // �ִ� 100*100 �迭�̴ϱ� �ִ� �̵� ���� 10000�� �ȴ�.

vector<pair<int, int>> dir;

void DFS(int x, int y, int depth);
void MakeDir();
int main() {
    // N��Mũ���� �迭�� ǥ���Ǵ� �̷�
    // ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����.
    // ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.
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
            map[i][j] = s[j]-'0'; // map �迭�� �Է� ���� �ֱ�
            visited[i][j] = 0; // visited �迭 �ʱ�ȭ
        }
    }
    MakeDir(); // �����¿� ��ǥ ���Ϳ� �Է�

    
    // �̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.
    // �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
    // �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.
    DFS(0, 0, 1);

    cout << ans << '\n';

    return 0;
}

void DFS(int x, int y, int depth) {
    // ��ǥ����(N, M)�� ���������� min�� �����ϰ� DFS��
    // (0, 0)���� �����ϴϱ� N-1, M-1�� (N, M)
    if (x == N-1 && y == M-1) {
        if (depth < ans) {
            ans = depth;
            //return;
        }
    }

    //cout << x << " "<< y << '\n';
    
    
    // 4����(=dir.size())���� Ž���ϸ鼭 map[N][M]=1 && visited[N][M]=0 �� �� �湮�ϱ�
    for (int i = 0; i < dir.size(); i++) {
        int nextN = x + dir[i].first;
        int nextM = y + dir[i].second;
        //cout << nextN << " " << nextM << '\n';
        // 
        // �� ����� Ž��x
        if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) continue;
        
        if (map[nextN][nextM]==1 && visited[nextN][nextM]==0) {
            // cout << "h" << '\n';
            // �湮üũ
            visited[x][y] = 1;
            DFS(nextN, nextM, depth + 1);
            visited[x][y] = 0;
        }
    }
    

}
void MakeDir() {
    dir.push_back(make_pair(-1, 0)); // ��
    dir.push_back(make_pair(1, 0)); //  ��
    dir.push_back(make_pair(0, -1)); // ��
    dir.push_back(make_pair(0, 1)); // ��
}