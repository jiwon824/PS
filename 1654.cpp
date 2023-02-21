// K개의 랜선을 잘라서 N개의 같은 길이의 랜선으로 만들 때, 만들 수 있는 최대 랜선의 길이를 구하는 프로그램
#include <iostream>
#include <algorithm>

#define MAX 10001
using namespace std;

// 만들어야 하는 N개의 랜선, 가지고 있는 K개의 랜선
// K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수. K ≦ N
long long N, K;
// K의 최대 범위인 10000으로 설정
long long cable[MAX];


int main(){
    // 첫 줄에 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력
    cin >> K >> N;

    long long maxi=0;
    // K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력
    for (int i=0; i<K; i++){
        cin >> cable[i];
        maxi = max(maxi, cable[i]);
    }

    // 이진탐색에 필요한 변수 선언 및 초기화
    // numOfCable은 mid 길이로 나눴을 때 나오는 케이블의 개수
    // ans는 numOfCable이 N보다 크거나 같아졌을 때의 mid 길이
    long long left, mid, right, numOfCable, ans;
    left=1, right=maxi, numOfCable=0, ans=0;

    while(left<=right){
        mid=(left+right)/2;
        
        for(int i =0;i<K;i++){
            numOfCable+=cable[i]/mid;
        }

        if (numOfCable<N){
            // N보다 작으면 right를 mid-1로 바꾸기
            right=mid-1;
            // 정답이 아니니까 numOfCable=0으로 하고 다시 mid 계산해서 나눠봐야함
            numOfCable=0;
        }
        else{ // if (numOfCable>=N)
            // 더 긴 게 답일 수 있으니까 ans에 있는 것과 mid 중 큰 값을 ans에 저장하고
            // left를 mid+1로 옮겨서 큰 수 로 나눠보기 numOfCable=0 초기화
            ans=max(ans, mid);
            left=mid+1;
            numOfCable=0;
        }
    }
        
    // N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력
    cout << ans << '\n';

    return 0;
}