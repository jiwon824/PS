#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int arr[100001]={0, };//사용자에게 입력받은 배열
    int DP[100001]={0, };
    // 주어지는 수는 -1000보다 크거나 같고, 1000보다 작거나 같은 정수니까 ans = -1000으로 초기화
    int n = 0, ans = -1000; 
    
    //입력
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++){
        DP[i] = max(DP[i-1]+arr[i], arr[i]);

        ans = max(DP[i], ans);
    }
    
    cout << ans << '\n';
    return 0;
}