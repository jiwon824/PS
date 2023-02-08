#include <iostream>


using namespace std;

int main(){
    // 첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.
    // int 최대값 2,147,483,647 int에 담아도 됨
    int N;
    cin >> N;
    
    // N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력
    // N이 1인 경우 아무것도 출력하지 않는다.
    // 2로 나누어 떨어지지 않아 i++ 되었다면, 2의 배수로는 안 나누어 떨어짐
    // 3으로 나누어 떨어지지 않아 i++ 되었다면, 3의 배수로는 안 나누어 떨어짐(반복)
    if (N==1) return 0;
    while (N>1){
        for (int i=2; i<=N; i++){
            if (N%i==0){
                cout << i << '\n';
                N/=i;
                break; // 안쪽 반복문(for) 탈출 다시 i는 2부터 N까지 반복
            }
        }
    }
    
    return 0;
}