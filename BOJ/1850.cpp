#include <iostream>
using namespace std;

long long gcd(long long a, long long b);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 두 자연수 A와 B를 이루는 1의 개수가 주어진다. 입력되는 수는 2^63보다 작은 자연수이다.
    long long A, B;
    cin >> A >> B;

    // 첫째 줄에 A와 B의 최대공약수를 출력한다. 정답은 천만 자리를 넘지 않는다
    long long ans = gcd(A, B);
    for (int i=0; i<ans; i++){
        cout << 1;
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
