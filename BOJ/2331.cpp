#include <iostream>
#include <cmath>

#define MAX 300001
using namespace std;

int visited[MAX];

void DFS(int a, int p);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 A(1 ≤ A ≤ 9999), P(1 ≤ P ≤ 5)가 주어진다.
    int A, P;
    cin >> A >> P;
    
    DFS(A, P);

    // 결과 출력
    // visited가 1인 수는 반복되지 않은 수
    int result = 0;
    for (int i = 0; i<MAX; i++){
        if(visited[i]==1) result++;
    }
    cout << result << '\n';
    
    return 0;
}
void DFS(int a, int p){
    visited[a]++;
    if (visited[a]==3) return;
    int sum = 0;
    // while(a)라고 해도 똑같이 작동하는 것 같다.
    while(a>0){
        // 각 자리수를 p제곱해서 sum에 더하기
        sum += (int)pow((a%10), p); 
        a /= 10;
    }
    DFS(sum, p);
}
