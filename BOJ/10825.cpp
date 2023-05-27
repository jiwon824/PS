#include <iostream>
#include <vector>
#include<tuple>
#include <algorithm>

using namespace std;
bool compare(const tuple<string, int, int , int> &a, const tuple<string, int, int , int> &b);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int ko, en, math;
    string name;

    // pair는 2개의 객체를 하나로 묶음
    // tuple은 3개 이상의 객체를 하나로 묶을 수 있음
    // 이름, 국어, 영어, 수학 점수 순서
    vector<tuple<string, int, int , int>> v;

    // +++ 입력 +++
    cin >> N;
    for (int i=0; i<N; i++){
        //이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다
        cin >> name >> ko >> en >> math;
        v.push_back(make_tuple(name, ko, en, math));
    }

    // +++ 정렬 +++
    sort(v.begin(), v.end(), compare);

    // +++ 출력 +++
    // 문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력
    // get<index>vector 로 tuple 안의 요소에 접근 가능
    /* 이런 식으로 출력할 수도 있음
    for (int i=0; i<N; i++){
        cout << get<0>(v[i]) << ' '; // v[i]의 첫 번째 요소: 이름
        cout << get<1>(v[i]) << ' '; // v[i]의 두 번째 요소: 국어
        cout << get<2>(v[i]) << ' '; // v[i]의 세 번째 요소: 영어
        cout << get<3>(v[i]) << '\n'; // v[i]의 네 번째 요소: 수학
    }
    */
   for (int i=0; i<N; i++){
        cout << get<0>(v[i]) << '\n'; // v[i]의 첫 번째 요소: 이름
    }

    return 0;
}


bool compare(const tuple<string, int, int , int> &a, const tuple<string, int, int , int> &b){
    //모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
    if(get<1>(a)==get<1>(b) && get<2>(a)==get<2>(b) && get<3>(a)==get<3>(b)) return get<0>(a) < get<0>(b);
    //국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
    if(get<1>(a)==get<1>(b) && get<2>(a)==get<2>(b)) return get<3>(a) > get<3>(b);
    //국어 점수가 같으면 영어 점수가 증가하는 순서로
    if(get<1>(a)==get<1>(b)) return get<2>(a) < get<2>(b);
    //국어 점수가 감소하는 순서로
    return get<1>(a) > get<1>(b);
}
