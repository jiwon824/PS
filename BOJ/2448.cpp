// https://ansohxxn.github.io/boj/2448/
#include <iostream>
using namespace std;

// 세로 N, 가로 2N-1
// 문제에서 k 의 최대값은 10 으로 주어졌으므로 행은 3∗2^{10}=3072행, 열은 3072∗2−1=6143열로 최대 크기로 배열을 선언
char star[3072][6144];

void draw(int x, int y);
void triangle(int x, int y, int n);
int main(){
    int N;
    cin >> N;

    // 별 찍기 전에 공백으로 초기화 해주기
    for (int i=0; i<N; i++){
        for (int j=0; j<2*N-1; j++){
                star[i][j] = ' ';
        }
    }

    triangle(0, N-1, N);//x좌표, y좌표, N값

    for (int i=0; i<N; i++){
        for (int j=0; j<2*N-1; j++){
            cout << star[i][j];
        }
        cout << '\n';
    }
    return 0;
}

void draw(int x, int y){
    // 맨 위
    star[x][y] = '*';
    
    // 2번째줄
    star[x + 1][y - 1] = '*';
    star[x + 1][y + 1] = '*';
    
    // 마지막 줄
    star[x + 2][y - 2] = '*';
    star[x + 2][y - 1] = '*';
    star[x + 2][y] = '*';
    star[x + 2][y + 1] = '*';
    star[x + 2][y + 2] = '*';
}
void triangle(int x, int y, int n){
    // n이 3이면 별 찍기
    if (n==3){
        draw(x, y);
        return; // return 해주는 거 중요
    }
    // 아니면 재귀함수 호출
    // n은 그대로 N값, x와 y로는 시작지점의 꼭대기
    triangle(x, y, n/2);  // 첫 번째 삼각형의 꼭짓점
    triangle(x+n/2, y-n/2, n/2);  // 두 번째 삼각형의 꼭짓점
    triangle(x+n/2, y+n/2, n/2);  // 세 번째 삼각형의 꼭짓점
}
