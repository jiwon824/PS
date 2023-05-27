#include <iostream>

using namespace std;

int main(){
    // 첫째 줄에 N(1 ≤ N ≤ 10,000,000)이 주어진다.
    int N;
    cin >> N;
    long long pentagon[N+2];
    pentagon[1] = 5;
    for (int i=2;i<=N+1;i++){
        // 첫째 줄에 N단계에서 점의 개수를 45678로 나눈 나머지를 출력
        pentagon[i] = (pentagon[i-1]+(i*3+1)) % 45678;
    }
    
    cout << pentagon[N] << '\n';
    return 0;
}
