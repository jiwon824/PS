#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;

int main(){
    // 둘째 줄부터 N개의 줄에는 수가 주어진다.
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // +++ 변수 선언 +++
    int N; // 첫 줄에 N개의 수가 주어짐 (1 ≤ N ≤ 1,000,000)

    // 둘째 줄부터 N개의 줄에 주어지는 수를 담는 배열
    // 주어지는 수는 절댓값이 1,000,000보다 작거나 같은 정수
    // 수는 중복되지 않는다.
    int Arr[MAX];

    // +++ 입력 +++
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> Arr[i];
    }

    // +++ 정렬 +++
    sort(Arr, Arr+N);

    // +++ 출력 +++
    for (int i=0; i<N; i++){
        cout << Arr[i] << '\n';
    }
    return 0;
}
