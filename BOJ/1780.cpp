#include <iostream>

using namespace std;

// 3^7=2187이므로 2200으로 선언해주기
int paper[2200][2200]; // N×N크기의 행렬로 표현되는 종이
int result[3]; // -1, 0, 1 종이가 몇 개인지 저장할 배열

bool check(int row, int col, int N);
void divide(int row, int col, int N);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다.
    int N;
    cin >> N;
    
    // 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.
    for (int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            tmp++; // -1,0,1 을 각각 0,1,2로 바꾸기
            paper[i][j]=tmp;
        }
    }
    
    // [0][0]부터 check->divide 반복
    divide(0, 0, N);

    // 첫째 줄에 -1로만 채워진 종이의 개수
    // 둘째 줄에 0으로만 채워진 종이의 개수
    // 셋째 줄에 1로만 채워진 종이의 개수를 출력
    for (int i=0; i<3; i++){
        cout << result[i] << '\n';
    }

    return 0;
}

bool check(int row, int col, int N){

    int start=paper[row][col];
    // 주어진 범위에 숫자가 같은지 확인
    for (int i=row; i<row+N; i++){
        for (int j=col; j<col+N; j++){
            if(start!=paper[i][j]) return false;
        }
    }
    return true;
}

void divide(int row, int col, int N){
    // 종이에 모든 숫자가 같으면 그 수로 이루어진 종이 개수 +1
    if (check(row, col, N)){
        // paper[row][col]에 0이 저장되어 있으면 result[0]++
        // 1이 저장되어 있으면 result[1]++, 2가 저장되어 있으면 result[2]++
        result[paper[row][col]]++;
    }
    // 종이에 적힌 숫자가 다르면 N/3으로 나눈 후 다시 check
    else{
        for (int i=row;i<row+N;i+=N/3){
            for (int j=col; j<col+N; j+=N/3){
                divide(i, j, N/3);
            }
        }
    }

}
