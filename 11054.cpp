#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int arr[1001]={0, };//사용자에게 입력받은 배열
    int leftDP[1001]={0, };// 앞에서부터 증가하는 최장 수열을 저장
    int rightDP[1001]={0, };// 뒤에서부터 증가하는 최장 수열을 저장
    int n = 0, ans = 0;
    
    //입력
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    //leftDP
    for (int i=1; i<=n; i++){
        //자신->자신이 최장이라서 최장길이의 최소값은 1이 된다.
        leftDP[i]=1;

        // 진행 방향 -> (왼쪽 값이 오른쪽 값보다 작아야 함)
        for (int j=i-1; j>=1; j--){
            if(arr[j] < arr[i]){
                leftDP[i] = max(leftDP[i], leftDP[j]+1);
            }
        }
    }
    //rightDP
    for (int i=n; i>=1; i--){
        //오른쪽부터 시작해서 1칸씩 줄이기
        //자신->자신이 최장이라서 최장길이의 최소값은 1이 된다.
        rightDP[i]=1;

        // <- 진행 방향 (왼쪽 값이 오른쪽 값보다 커야 함)
        for (int j=n; j>=i; j--){
            if(arr[j] < arr[i]){
                rightDP[i] = max(rightDP[i], rightDP[j]+1);
            }
        }
    }

    //answer
    for (int i=1; i<=n; i++){
    ans = max(leftDP[i]+rightDP[i]-1, ans);
    }
    cout << ans;
}