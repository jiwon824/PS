#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)가 주어진다
    int N, K;
    cin >> N >> K;
    
    vector <long long> vec(N);
    // 둘째에는 A1, A2, ..., AN이 주어진다. (-10^9 ≤ A_i ≤ 10^9)
    for (int i=0; i<N; i++){
        cin >> vec[i];
    }

    // A를 오름차순 정렬했을 때,
    sort(vec.begin(), vec.end());

    // 앞에서부터 K번째 있는 수를 구하는 프로그램
    cout << vec[K-1];

    return 0;
}
