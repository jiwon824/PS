#include <iostream>

using namespace std;


int map[65][65];

bool check(int row, int col, int N);
void divide(int row, int col, int N);
int main(){
    // 첫째 줄에는 영상의 크기를 나타내는 숫자 N(1 ≤ N ≤ 64)
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    divide(0, 0, N);
    return 0;
}

bool check(int row, int col, int N){

    int start=map[row][col];
    // 주어진 범위에 숫자가 같은지 확인
    for (int i=row; i<row+N; i++){
        for (int j=col; j<col+N; j++){
            if(start!=map[i][j]) return false;
        }
    }
    return true;
}

void divide(int row, int col, int N){
    // 모든 숫자가 같으면
    if (check(row, col, N)){
        cout << map[row][col];
    }
    // 숫자가 다르면 한 변의 길이를 N/2으로 나눈 후 다시 check
    else{
        for (int i=row;i<row+N;i+=N/2){
            for (int j=col; j<col+N; j+=N/2){
                cout << '(';
                divide(i, j, N/2);
            }
        }
    }

}