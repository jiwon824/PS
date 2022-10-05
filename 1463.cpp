#include <iostream>
#include <vector>

using namespace std;

int main(){
    
//1463 1로 만들기
    int X;
    cin >> X;
    vector<int> DP(X+1, 0);

    for (int i=2; i<=X;i++){
        //1을 뺀 경우를 우선 DP[i]에 저장
        DP[i]=DP[i-1]+1;
        //2로 나누어 떨어지면
        //DP[i]에 들어있는 수(지금은 DP[i-1]+1)와 2로 나눈 DP 값에 1을 더한 값 중 최소
        if (i%2==0) DP[i] = min(DP[i], DP[i/2]+1);
        //3으로 나누어 떨어지는 경우
        //DP[i]에 들어있는 수(지금은 2로 떨어졌으면, 2로 나눈 거+1 vs 1뺀 것+1)와 3으로 나눈거+1 중 최소
        if (i%3==0) DP[i] = min(DP[i], DP[i/3]+1);
    }
    cout << DP[X] << '\n';
    return 0;
}