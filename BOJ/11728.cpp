#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
    int N, M;
    cin >> N >> M;
    // 둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 10^9보다 작거나 같은 정수이다.
    int A[N+1], B[M+1];
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    for (int i=0; i<M; i++){
        cin >> B[i];
    }

    int AIdx=0, BIdx=0;
    // AIdx랑 BIdx가 주어진 N, M범위 안에 있을 동안 반복
    while (AIdx<N && BIdx<M){
        // A의 AIdx번째 원소와 B의 BIdx번째 원소 중 작은 것을 출력하고,
            // AIdx번째 원소를 출력했다면, AIdx를 1증가시켜 다음 원소를 가리키도록 만듦
            // BIdx번째 원소를 출력했다면, BIdx를 1증가시켜 다음 원소를 가리키도록 만듦
        if (A[AIdx]<=B[BIdx]) cout << A[AIdx++] << " ";
        else cout << B[BIdx++] << " ";
    }
    // A의 원소가 6개고, B의 원소가 2개라면, AIdx<N && BIdx<M에서 원소 2개 밖에 보지 못한다.
    // 원소 개수가 차이날 경우를 대비해 비교하여 출력 후, 배열에 남은 원소를 출력하는 부분을 따로 써줘야 한다.
    while(AIdx<N){
        cout << A[AIdx++] << " ";
    }
    while(BIdx<M){
        cout << B[BIdx++] << " ";
    }
    cout << '\n';
    return 0;
}
