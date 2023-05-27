#include <iostream>
#include <array>
using namespace std;

long long gcd(long long a, long long b);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다.
    int t;
    cin >> t;
    for (int i=0; i<t;i++){
        // 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고,
        int n;
        cin >> n;
        long long arr[101] ={0, };
        // 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        //가능한 모든 쌍의 GCD의 합 출력
        long long ans = 0;
        for (int i = 0; i<n; i++){
            for (int j=i+1; j<n; j++){
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

long long gcd(long long a, long long b){
    // 두 수 중 하나라도 0이 되면 종료
    while (a != 0 and b != 0){
        if (a > b) a= a % b; // 나머지 연산
		else b = b % a;
    }
    return a + b;
}
