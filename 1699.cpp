#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int DP[100001]={0, };
    int n = 0; 
    
    //입력
    cin >> n;

    for (int i=1; i<=n; i++){
        DP[i] = i; //1^2을 i번 더하면 i가 된다.

        for (int j=1; j*j<=i; j++){
            /*예를 들어, dp[5]의 경우
                dp[5]=dp[5-1*1]+1=dp[5-1]+1 (dp[4]인 경우에 1을 제곱한 값을 더한 경우)
                dp[5]=dp[5-2*2]+1=dp[5-4]+1 (dp[1]인 경우에 2를 제곱한 값을 더한 경우)*/
            DP[i] = min(DP[i], DP[i-j*j]+1);
            
        }
    }

    cout << DP[n];
    
    return 0;
}