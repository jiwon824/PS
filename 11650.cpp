#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int x, y;
    vector<pair<int, int>> v;
    cin >> N;
    
    // +++ 입력 +++
    for (int i=0; i<N; i++){
        cin >> x >> y;
        v.push_back({x, y}); //v.push_back(x, y); 이렇게 쓰면 에러남
        //v.push_back(make_pair(x, y)); 이렇게 쓸 수도 있는 것 같다.
    }

    // +++ 정렬 +++
    sort(v.begin(), v.end());

    // +++ 출력 +++
    for (int i=0; i<N; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}