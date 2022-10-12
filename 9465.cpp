#include <iostream>
#include <algorithm>

using namespace std;
//arr는 사용자에게 입력받은 점수판 배열
//maxSticker는 최대 값을 구하기 위한 누적합? 배열
long long maxSticker[2][100001]={0, };
long long arr[2][100001]={0, };

int main(){
//9465 스티커
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int testCase, n;
    cin >> testCase;

    for (int t=0; t<testCase; t++){
        //스티커 점수판(원본배열) 입력받기
        cin >> n;
        //첫 번째 줄 입력
        for (int j=0; j<n; j++){
            cin >> arr[0][j]; 
        }
        //두 번째 줄 입력
        for (int j=0; j<n; j++){
            cin >> arr[1][j]; 
        }

    //최대 배열 계산 약간 누적합 같은 느낌
        maxSticker[0][0]=arr[0][0];
        maxSticker[1][0]=arr[1][0];
        maxSticker[0][1]=arr[0][1]+maxSticker[1][0];
        maxSticker[1][1]=arr[1][1]+maxSticker[0][0];

        for (int j=2;j<n;j++){
            maxSticker[0][j]=max(maxSticker[1][j-2], maxSticker[1][j-1])+arr[0][j];
            maxSticker[1][j]=max(maxSticker[0][j-2], maxSticker[0][j-1])+arr[1][j];
        }

        //0부터 시작했으니까 인덱스 n-1이 우리가 원하는 n
        cout << max(maxSticker[0][n-1], maxSticker[1][n-1]) << '\n';

    }

    return 0;
}