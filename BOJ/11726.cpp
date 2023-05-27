#include <iostream>
#include <vector>

using namespace std;

int main(){
//11726 2×n 타일링
    int N;
    cin >> N;
    vector<int> dp(N+1, 0);
    dp[1]=1;
    dp[2]=2;
    for (int i=3;i<=N;i++){
        dp[i]=(dp[i-2]+dp[i-1]) % 10007;
    }
    cout << dp[N] << '\n';
    return 0;
}
