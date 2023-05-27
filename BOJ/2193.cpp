#include <iostream>

using namespace std;

int main(){
//2193 이친수
    int n;
    long long dp[91]={0, };
    cin >> n;

    //배열 채우기
    dp[1]=1;
    dp[2]=1;
    for (int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout << dp[n] <<'\n';
    return 0;
}
