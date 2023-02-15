#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 26
using namespace std;

int N; // 지도 크기 N 
int map[MAX][MAX]; // 지도
bool visited[MAX][MAX];
int dir[4][2]={{-1, 0},{0, 1},{1, 0},{0, -1}}; //상하좌우 이동
vector<int> complex; // 단지랑 단지 안에 집의 수 저장
int cnt=0; // 단지 내 집 개수(세서 벡터에 push)

void DFS(int x, int y);
int main(){
    // 지도 크기 N 입력 받기
    cin >> N;

    //string으로 입력받아서 2차원 배열에 넣기
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        // 이차원 배열
        // arr[0][0] arr[0][1] arr[0][2]
        // arr[1][0] arr[1][1] arr[1][2]
        for (int j=0;j<N;j++){
            // string.at(j)는 string[j]와 같은 역할을 하지만,
            // at멤버 함수는 pos가 문자열 내에 유효한 위치인지 판단하여 그렇지 않은 경우
            // out_of_range 에러를 발생시킨다. (string[j]를 쓰면 프로그램이 죽음)
            // at함수가 좀 더 안전하다고 할 수 있다.
            map[i][j]=tmp.at(j)-'0';
        }
    }

    // DFS로 단지 묶기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            // 아파트 있음+방문한 적 없는 아파트
            if(map[i][j]==1&&visited[i][j]==0){
                cnt++;
                DFS(i, j);
                complex.push_back(cnt);
                cnt=0;
            }
        }
    }
    // 단지 개수 출력
    cout << complex.size()<<'\n';
    // 단지별 가구수 오름차순 출력
    sort(complex.begin(), complex.end());
    for(int i=0;i<complex.size();i++){
        cout << complex[i]<<'\n';
    }

    return 0;
}

void DFS(int x, int y){
    visited[x][y]=1; // 방문했음 체크
    for(int i=0;i<4;i++){
        //nx, ny는 nextX, nextY
        int nx = x +dir[i][0];
        int ny = y +dir[i][1];

        // x, y 범위가 0~N 사이가 아니면 넘어가기
        if(nx<0 || ny<0 || nx>N || ny>N) continue;
        // nx, ny 위치에 집이 있으면서 방문한 적 없는 집일 경우 DFS
        // 단지내 집 개수+=1
        if(map[nx][ny]==1 && visited[nx][ny]==0){
            cnt++;
            DFS(nx, ny);
        }
    }
}