#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;

int main(){
    // 이 코드 없으면 시간초과 뜸
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다.
    int N;
    cin >> N;
    // 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. (-10,000,000<= 숫자 카드에 적혀있는 수 <=10,000,000)
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    // 이진 탐색해야 하니까 카드 순서대로 정렬하기
    sort(card.begin(), card.end());

    // 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다.
    int M;
    cin >> M;
    // 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수
    for (int m=0; m<M; m++){
        int tmp;
        cin >> tmp;

        // 이진탐색으로 있는지 확인하기
        int left=0, right=N-1;
        bool searched=false;
        while (left<=right){
            // 인덱스의 절반 부분을 살펴보기
            int mid=(left+right)/2;
            if (card[mid]==tmp){
                searched=true;
                break;
            }
            else if (card[mid]<tmp) left=mid+1;
            else right=mid-1;
        }
        // 탐색을 마쳤을 때 searched=1이면 1, 0이면 0출력
        cout << searched << " ";
    }
    return 0;
}