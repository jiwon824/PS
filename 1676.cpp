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

    // N!을 NFac에 저장하고, 10으로 나누어 떨어지면 맨 뒤 숫자가 0이라는 뜻
    // 10으로 나눠주고 zeroNum을 1증가 시켜준다.
    long long NFac=factorial[N];
    int zeroNum =0;
    while (NFac%10==0){
        NFac/=10;
        zeroNum++;
    }

    // N!을 출력
    cout << zeroNum << '\n';
    return 0;
} 
