#include <iostream>
#include <algorithm>
using namespace std;

// n은 2, 5의 개수를 셀 원래 숫자, x는 2 또는 5
long long solution(int n, int x);
int main(){
    // 첫째 줄에 정수 n, m (0 ≤ m ≤ n ≤ 2,000,000,000, n!=0)이 주어진다.
    // int 최대값 2,147,483,647 int에 담아도 됨
    int n, m;
    cin >> n >> m;

    long long two=0; // 2의 개수
    long long five=0; // 5의 개수

    // nCm = n!/ (n-m)! * m!
    // 나누면 없어지므로 n에서의 2, 5를 구한 후, 거기서 (n-m에서의 2, 5와 m에서의 2, 5)를 빼야한다
    two = solution(n, 2) - solution(n-m, 2) - solution(m, 2);
    five = solution(n, 5) - solution(n-m, 5) - solution(m, 5);

    cout << min(two, five) << '\n';
    return 0;

}

//왜 반환형을 long long으로 해줘야 integer overflow가 안 나는 걸까
long long solution(int n, int x){
    long long xNum = 0;
    for (long long i =x;i<=n; i*=x){
        xNum += n/i;
    }
    return xNum;
}
