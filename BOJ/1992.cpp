#include <iostream>
#include <string>

using namespace std;

int map[65][65];

void divide(int row, int col, int N);
int main(){
    // 첫째 줄에는 영상의 크기를 나타내는 숫자 N(1 ≤ N ≤ 64)
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string s;
        cin >> s;
        for (int j=0; j<N; j++){
            map[i][j]=s[j]-'0';
        }
    }
    divide(0, 0, N);
    return 0;
}

void divide(int row, int col, int N){
    int start=map[row][col];
    for (int i=row; i<row+N; i++){
        for (int j=col; j<col+N; j++){
            // 다르면 N/2 사이즈로 쪼개기
            if(start!=map[i][j]){
                cout << "(";
                // 이차원 배열
                    // arr[0][0] arr[0][1] arr[0][2]
                    // arr[1][0] arr[1][1] arr[1][2]
                // 현재 위치 왼쪽 위 (row, col)
                divide(row, col, N/2);
                // 오른쪽 위
				divide(row, col+N/2, N/2);
                // 왼쪽 아래
				divide(row+N/2, col, N/2);
                // 오른쪽 아래
				divide(row+N/2, col+N/2, N/2);
				cout << ")";
				return;
            }
        }
    }
    cout << map[row][col];
}
