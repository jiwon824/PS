#include <iostream>

#define mod 1000000000
using namespace std;

int main(){
//10844 쉬운 계단 수
    //첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.
    //[101] 100의 길이를 가지면서, [10] 0~9로 끝나는 배열
    int dp[101][10]={0, };
    int n, ans=0;
    cin >>n;

    //배열 채우기
    //길이가 1이면서 1~9로 끝나는 수의 계단은 1개
    //0으로 시작하는 수는 계단수가 아니다.
    //dp[1][0]=0이고, dp[1][1~9]는 1이니까 i는 1부터 9까지 반복
    for (int i=1;i<10;i++){
        dp[1][i]=1; 
    }
    //i의 길이를 가지면서 j로 끝나는 수
    //길이가 0인 경우는 없고, i=1인 경우([1][])는 채웠으니까 i는 2부터 시작
    for(int i=2;i<=n;i++){
        for(int j=0; j<10;j++){
            if (j==0){
                dp[i][j]= dp[i-1][j+1];
            }
            else if (j==9){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                dp[i][j]= dp[i-1][j+1] + dp[i-1][j-1];
            }
            dp[i][j]%=mod;
        }
    }

    //정답 저장&출력
    for (int j=0;j<10;j++){
        ans+=dp[n][j];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
