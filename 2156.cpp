#include <iostream>
#include <algorithm>

using namespace std;

 //(1 ≤ n ≤ 10,000) (0 ≤ amount ≤ 1,000)
//amount는 사용자 입력, maxWine은 최대 와인 수를 구하는 배열
int amount[10001] = {0, };
int maxWine[10001] = {0, };

int main(){
//2156 포도주 시식
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //포도주 가 몇 잔인지 입력
    int n;
    cin >> n;
    //포도주의 양 입력
    for(int i=1;i<=n;i++){
        cin >> amount[i];
    }

    //최대 포도주 계산
    maxWine[1]=amount[1];
    maxWine[2]=amount[1]+amount[2];
    for (int i=3;i<=n;i++){
        maxWine[i]=maxWine[i-1];
        maxWine[i]=max(maxWine[i], maxWine[i-3]+amount[i-1]+amount[i]);
        maxWine[i]=max(maxWine[i], maxWine[i-2]+amount[i]);
    }

    cout << maxWine[n] << '\n';

    return 0;
}