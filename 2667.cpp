#include <iostream>

#define MAX 26
using namespace std;

int map[MAX][MAX];
bool check[MAX][MAX];
int dir[4][2]={{-1, 0},{0, 1},{1, 0},{0 -1}}; //상하좌우 이동
vector<int> complex; // 단지랑 단지 안에 집의 수 저장
int cnt=0; // 단지 내 집을 셀 변수(세서 벡터에 push)

int main(){
    int N;
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

    for (int w=0;w<N;w++){
        for (int v=0;v<N;v++){
            cout << map[w][v];
        }
        cout <<'\n';
    }
    return 0;
}