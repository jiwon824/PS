#include <iostream>

using namespace std;

int main(){
    // 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
    int N, K;
    cin >> N >> K;
    int coin[N+1];
    for (int i=0; i<N; i++){
        cin >> coin[i];
    }
    
    int cnt=0;
    for (int i=N-1;i>=0;i--){
        cnt+=K/coin[i];
        K%=coin[i];
    }
    cout << cnt << '\n';
    return 0;
}
