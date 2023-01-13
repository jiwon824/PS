#include <iostream>
#include <algorithm>

#define MAX 201
#define MOD 1000000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    long long DP[MAX][MAX] = {0, };

    cin >> n >> k;
    for (int i = 1; i<=k;i++){
        DP[i][1] = 1;
        DP[1][i] = i;
    }

    for (int i=2; i<=n; i++){
        for (int j=1; j<=k; j++){
            // 이차원배열[가로][세로]
            //답을 1,000,000,000으로 나눈 나머지를 출력
            DP[i][j]= (DP[i-1][j]+DP[i][j-1]) % MOD;
        }
    }
    
    cout << DP[n][k];

    return 0;
}