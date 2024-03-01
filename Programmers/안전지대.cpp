#include <iostream>
#include <vector>

using namespace std;
// board[i-1][j-1] board[i-1][j] board[i-1][j+1]
// board[i][j-1]  (board[i][j]) board[i][j+1]
// board[i+1][j-1] board[i+1][j] board[i+1][j+1]
int dx[8] ={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] ={-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    vector<vector<int>> board;

    // input
    int n;
    cin >> n;
    for (int i =0; i<n;i++){
        for(int j=0;j<n;j++){
            cin >>board[i][j];
        }
    }

    // danger area check
    for (int i =0; i<board.size();i++){
        for (int j =0;j<board[0].size();j++){
            if(board[i][j] == 1){ 
                // i j를 감싼 8개의 칸 = 2로 설정 **단 벡터의 범위를 넘어가지 않을 때만
                for (int k =0;k<8;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size()) continue;

                    if (board[nx][ny] == 0) board[nx][ny] = 2;
                }
            }
        }
    }

    // print safe area
    int answer =0;
    for (int i =0; i<board.size();i++){
        for (int j =0;j<board[0].size();j++){
            if(board[i][j] == 0) answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}