#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
    int N;
    cin >> N;
    queue <int> q;
    // 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
    // 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
    string command;
    for (int i=0; i<N; i++){
        cin >> command;
        // push X: 정수 X를 큐에 넣는 연산이다.
        if (command=="push"){
            int X;
            cin >> X;
            q.push(X);
        }
        // pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
        // 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command=="pop"){
            if (q.empty()) cout << "-1" << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        // size: 큐에 들어있는 정수의 개수를 출력한다.
        else if (command=="size"){
            cout << q.size() << '\n';
        }
        // empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
        else if (command=="empty"){
            cout << q.empty() << '\n';
        }
        // front: 큐의 가장 앞에 있는 정수를 출력한다.
        // 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command=="front"){
            if (q.empty()) cout << "-1" << '\n';
            else cout << q.front() << '\n';
        }
        // back: 큐의 가장 뒤에 있는 정수를 출력한다.
        // 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else {
            if (q.empty()) cout << "-1" << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}