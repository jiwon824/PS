#include <iostream>
#include <vector>

using namespace std;

int main(){
//9095 1, 2, 3 더하기
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> dp(12, 0);
    int tc, n;
    cin >> tc;

    //dp배열 채우기
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for (int i=4; i<=dp.size();i++){
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }

    //testcase 정답 출력
    for (int i=0; i<tc;i++){
        cin >> n;
        cout << dp[n] <<'\n';
    }
    
    return 0;
}
