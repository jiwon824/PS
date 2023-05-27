#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int card; // 구매하려고 하는 카드의 개수
    int cardPack[1001] = {0, }; // cardPack[들어있는 카드 개수] = 카드팩 가격
    int DP[1001] = {0, };

    // 입력
    cin >> card;
    for (int i=1; i<=card; i++){
        cin >> cardPack[i];
    }
    
    for (int i=1; i<=card; i++){
        // DP[i] i개 샀을 때, 최대 카드팩 가격
        for (int j=1; j<=i;j++){
            DP[i] = max(DP[i], DP[i-j] + cardPack[j]);
        }
    }
    cout << DP[card] <<'\n';

    return 0;
}
