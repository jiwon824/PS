#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    int DP[10001] = {0, };
    cin >> n;

    // 홀수를 2*1/1*2로 채우는 방법은 없음
    if (n%2 == 1){
        cout << "0" << "\n";
        return 0;
    }

    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for(int i=4; i<=n; i+=2){ //홀수는 필요 없으니까 +2해서 짝수만 봄
        DP[i] = DP[i-2] * DP[2];
        for (int j=i-4; j>=0; j--){
            DP[i] = DP[i] + (DP[j] * 2);
        }
    }

    cout << DP[n];
    return 0;
}
