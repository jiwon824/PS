#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    queue<int> Josephus;
    // queue에 숫자 집어 넣기
    for (int i=1; i<=N; i++){
        Josephus.push(i);
    }

    cout << '<';

    while(Josephus.size()>1){
        int tmp;
        // k번째 사람 찾기
        for(int i=1;i<K;i++){
            tmp = Josephus.front();
            Josephus.push(tmp);
            Josephus.pop();
        }
        // K번째 사람 출력 후 제거
        tmp = Josephus.front();
        cout << tmp << ", ";
        Josephus.pop();
    }

    cout << Josephus.front() << '>';

    return 0;
}
