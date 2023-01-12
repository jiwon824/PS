#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int stairs[301]={0, }; // 계단[개수] = {점수, }
    int DP[10001]={0, }; // DP[N] = N번째 계단을 반드시 밟았을 때, 최대 점수
    int n = 0; // 계단 개수
    
    //입력
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> stairs[i];
    }
    
    DP[1]=stairs[1];
    DP[2]=stairs[1]+stairs[2];
    for(int i =3; i<=n;i++){
        DP[i] = max(DP[i-2] + stairs[i], DP[i-3] + stairs[i-1]+stairs[i]);
    }

    cout << DP[n];
    return 0;
}