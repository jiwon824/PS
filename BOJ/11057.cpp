#include <iostream>

using namespace std;

int main(){
//11057 오르막 수
    //첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.
    //[1001] 1000의 길이를 가지면서, [10] 0~9로 끝나는 배열
    int dp[1001][10]={0, };
    int n, ans=0;
    cin >> n;

    //배열 채우기
    //수는 0으로 시작할 수 있다.
    //길이가 1이면서 0~9로 끝나는 경우 = 1가지
    for (int j=0; j<10; j++){
        dp[1][j]=1;
    }
    //길이가 2~n이면서 0~9로 끝나는 경우
    for (int i=2; i<=n; i++){
        for (int j=0; j<10; j++){
            if (j == 0) {
                dp[i][0] = 1;
                continue;
            }

            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 10007;
        }
    }

    //정답 계산&출력
    for (int j=0;j<10;j++){
        ans+=dp[n][j];
        ans %= 10007;
    }

    cout << ans << '\n';
    return 0;
}
