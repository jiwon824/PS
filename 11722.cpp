#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int arr[1001]={0, };//사용자에게 입력받은 배열
    int DP[1001]={0, };
    int n = 0, ans = 0;
    
    //입력
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++){
        //자신->자신이 최장이라서 최장길이의 최소값은 1이 된다.
        DP[i]=1;

        //지금 검사하는 수의 바로 전 수가 현재 수보다 작은지 검사
        for (int j=i-1; j>=1; j--){
            if(arr[j] > arr[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        ans = max(DP[i], ans);
    }

    cout << ans << '\n';
    return 0;
}