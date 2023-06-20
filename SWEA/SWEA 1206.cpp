#include <iostream>
#define MAX 1001

using namespace std;


int buildings[MAX];
int N;

int solution();
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 총 10개의 테스트케이스가 주어진다.
    for (int tc=0; tc<10; tc++){
        // 입력
        // 각 테스트케이스의 첫 번째 줄에는 건물의 개수 N이 주어진다. (4 ≤ N ≤ 1000)
        cin >> N;
        for (int i=0; i<N; i++){
            // 그 다음 줄에는 N개의 건물의 높이가 주어진다. (0 ≤ 각 건물의 높이 ≤ 255)
            cin >> buildings[i];
        }

        // #부호와 함께 테스트케이스의 번호를 출력하고, 공백 문자 후 조망권이 확보된 세대의 수를 출력한다.
        int ans = solution();
        cout << '#' << tc+1 << ' ' << ans << '\n';
    }
    return 0;
}

int solution(){
    int maxHeight=0, ans=0;
    // 맨 왼쪽 두 칸과 맨 오른쪽 두 칸에 있는 건물은 항상 높이가 0이다. 
    for (int i=2; i<N-2; i++){
        // 최대값 초기화
        maxHeight = 0;
        // i-2, i-1, i+1, i+2 중에서 최대 값을 maxHeight에 저장하기
        for (int j=i-2; j<=i+2; j++){
            if (j==i) continue;
            // 최대값 저장하기
            if (buildings[j]>maxHeight) maxHeight = buildings[j];
        }
        if (buildings[i]-maxHeight<=0) continue;
        else ans += buildings[i]-maxHeight;
    }

    return ans;
}