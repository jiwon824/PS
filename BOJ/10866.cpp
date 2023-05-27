#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
    int N;
    cin >> N;
    deque <int> dq;

    // 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
    // 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
    string command;
    for (int i=0; i<N; i++){
        cin >> command;
        // push_front X: 정수 X를 덱의 앞에 넣는다.
        if (command=="push_front"){
            int X;
            cin >> X;
            dq.push_front(X);
        }
        // push_back X: 정수 X를 덱의 뒤에 넣는다.
        else if (command=="push_back"){
            int X;
            cin >> X;
            dq.push_back(X);
        }
        // pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.
        // 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command=="pop_front"){
            if (dq.empty()) cout << "-1" << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        // pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.
        // 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command=="pop_back"){
            if (dq.empty()) cout << "-1" << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        // size: 덱에 들어있는 정수의 개수를 출력한다.
        else if (command=="size"){
            cout << dq.size() << '\n';
        }
        // empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
        else if (command=="empty"){
            cout << dq.empty() << '\n';
        }
        // front: 덱의 가장 앞에 있는 정수를 출력한다.
        // 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command=="front"){
            if (dq.empty()) cout << "-1" << '\n';
            else cout << dq.front() << '\n';
        }
        // back: 덱의 가장 뒤에 있는 정수를 출력한다.
        // 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else {
            if (dq.empty()) cout << "-1" << '\n';
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}
