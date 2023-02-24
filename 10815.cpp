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
    vector <int> MCard;
    // 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수
    for (int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        // upper_bound를 해주게 되면 이분탐색으로 해당 숫자가 끝나는 위치를 반환
        // lower_bound는 이분탐색으로 해당 숫자가 시작되는 위치를 반환
        auto upper = upper_bound(card.begin(), card.end(), tmp);
        auto lower = lower_bound(card.begin(), card.end(), tmp);
        
        cout << upper-lower << " ";
    }
    return 0;
}