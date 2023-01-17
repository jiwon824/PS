#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<int, string> &a, const pair<int, string> &b);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int x;
    string y;
    vector<pair<int, string>> v;

    // +++ 입력 +++
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> x >> y;
        v.push_back({x, y}); //v.push_back(x, y); 이렇게 쓰면 에러남
        //v.push_back(make_pair(x, y)); 이렇게 쓸 수도 있는 것 같다.
    }

    // +++ 정렬 +++
    stable_sort(v.begin(), v.end(), compare);

    // +++ 출력 +++
    for (int i=0; i<N; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}

bool compare(const pair<int, string> &a, const pair<int, string> &b){
    return a.first < b.first;
}