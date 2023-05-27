#include <iostream>

using namespace std;

int gcd(int a, int b);
int main(){
    // 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.
    int T;
    cin >> T;
    // 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)
    for (int i=0;i<T;i++){
        int A, B;
        cin >> A >> B;
        cout << A*B/gcd(A, B) << '\n';
    }
    return 0;
}
int gcd(int a, int b){
    // 두 수 중 하나라도 0이 되면 종료
    while (a != 0 and b != 0){
        if (a > b) a= a % b; // 나머지 연산
		else b = b % a;
    }
    return a + b;
}
