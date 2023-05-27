#include <iostream>
#include <algorithm>

using namespace std;

//먹을 수 있는 최대 사탕 개수
int maxCandy=0; 
void check(char candy[51][51], int n); //가로세로 최대 사탕 개수를 체크하는 함수
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    char candy[51][51];//51*51 2차원 배열 생성
    //배열 크기(n*n) 입력 받은 후, 색을 입력 받음
    int n;
    cin >> n;
    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
        cin >> candy[i][j];
        }
    }

    //가로 swap하고 check 원상복구
    for (int i=0; i<n; i++){
        for (int j=0; j+1<n; j++){
            //상근이는 사탕의 색이 다른 인접한 두 칸을 고른다.
            if (candy[i][j]==candy[i][j+1]) continue;

            swap(candy[i][j], candy[i][j+1]);
            check(candy, n);
            swap(candy[i][j], candy[i][j+1]);
        }
    }

    //세로 swap하고 check 원상복구
    for (int j=0; j<n; j++){
        for (int i=0; i+1<n; i++){
            //상근이는 사탕의 색이 다른 인접한 두 칸을 고른다.
            if (candy[i][j]==candy[i+1][j]) continue;
            
            swap(candy[i][j], candy[i+1][j]);
            check(candy, n);
            swap(candy[i][j], candy[i+1][j]);
        }
    }
    cout << maxCandy << '\n';
    return 0;
}

void check(char candy[51][51], int n){
    int cnt=1; //최소 1개의 사탕은 먹을 수 있음
    //가로 검사
    for (int i=0; i<n; i++){
        for (int j=0; j+1<n; j++){
            if (candy[i][j]==candy[i][j+1]) cnt+=1; //가로가 같으면 cnt+1
            else break;//다르면 이 줄에서는 cnt 끝 -> break;
        }
        if (cnt>maxCandy) maxCandy=cnt; //cnt가 max값보다 크면 max 갱신
        cnt = 1; //다음 줄을 위해 cnt 초기화
    }

    //세로 검사
    for (int j=0; j<n; j++){
        for (int i=0; i+1<n; i++){
            if (candy[i][j]==candy[i+1][j]) cnt+=1; //세로가 같으면 cnt+1
            else break;//다르면 이 줄에서는 cnt 끝 -> break;
        }
        if (cnt>maxCandy) maxCandy=cnt; //cnt가 max값보다 크면 max 갱신
        cnt = 1; //다음 줄을 위해 cnt 초기화
    }
}
