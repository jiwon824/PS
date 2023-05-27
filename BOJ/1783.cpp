// https://jaimemin.tistory.com/598
// https://codejin.tistory.com/169
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // 첫째 줄에 체스판의 세로 길이 N와 가로 길이 M이 주어진다. N과 M은 2,000,000,000보다 작거나 같은 자연수
    int N, M;
    cin >> N >> M;

    // 2칸 위로, 1칸 오른쪽
    // 1칸 위로, 2칸 오른쪽
    // 1칸 아래로, 2칸 오른쪽
    // 2칸 아래로, 1칸 오른쪽

    // 세로3 가로7이 되어야 4가지 방법을 모두 한 번씩 사용(5번 방문)가능
    // 세로가 1줄
    if (N==1) cout << 1 <<'\n';
    // 세로 2줄
    // 1부터 시작하여 2, 3번의 움직임은 가로 2칸을 움직이기 때문에 (가로의 길이 + 1) / 2가 곧 칸의 개수
    // 등차수열을 배우면 당연한 이야기...?
    else if (N==2) cout << min(4, (M+1)/2) << '\n';
    // 세로가 3줄 이상 = 1, 2, 3, 4가 한 번씩 나올 수 있음
    else {
        if (M<=6){
            cout << min(4, M) << '\n';
        }
        else {
            cout << M-2 << '\n';
        }
    }

    return 0;
}
