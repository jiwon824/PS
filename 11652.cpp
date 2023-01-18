#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // +++ 변수 선언 +++
    int N; // 첫 줄에 N개의 수가 주어짐 (1 ≤ N ≤ 100,000)
    cin >> N;

    //N개의 줄에는 수가 주어진다.
    //이 수는 -2^{62}보다 크거나 같고, 2^{62}보다 작거나 같다.
    vector<long long> v(N);
    
    // +++ 입력 +++
    for (int i=0; i<N; i++){
        cin >> v[i];
    }

    // +++ 정렬 +++
    sort(v.begin(), v.end());

    // 가장 중복이 많은 수 찾기
    // 1112234444 이런 식으로 들어가 있을 거니까
    int cnt=0, max=0;
    long long answer=v[0];
    for (int i=0; i<N-1; i++){

        if (v[i]==v[i+1]){ //앞뒤 수가 동일한 수일 경우
            cnt+=1;
            if (max<cnt){
                max=cnt;
                answer = v[i];
            }
        }

        else { // 같지 않으면 cnt 0으로 초기화
            cnt = 0;
        }
    }

    // +++ 출력 +++
    cout << answer;
    return 0;
}