#include <iostream>

using namespace std;

int main(){
    // 첫째 줄에 N(0 ≤ N ≤ 500)이 주어진다.
    int N;
    cin >> N;
    // 팩토리얼 저장
    long long factorial[N+1];
    factorial[0]=1;
    factorial[1]=1;
    for (int i=2;i<=N;i++){
        factorial[i] = factorial[i-1]*i;
    }
    // N!을 출력
    cout << factorial[N] << '\n';
    return 0;
} 
