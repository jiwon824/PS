#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
    int N;
    cin >> N;
    stack<int> s;

    for (int i=0; i<N; i++){
        string command;
        cin >> command;
        // push X: 정수 X를 스택에 넣는 연산
        if (command =="push"){
            int X;
            cin >> X;
            s.push(X);
        }
        // pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
        // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if (command =="pop"){
            if (s.empty()) cout << "-1" << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        // size: 스택에 들어있는 정수의 개수를 출력한다.
        else if (command =="size"){
            cout << s.size() << '\n';
        }
        // empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
        else if (command =="empty"){
            if(s.empty()) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
        // top: 스택의 가장 위에 있는 정수를 출력한다.
        // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else{
            if (s.empty()) cout << "-1" << '\n';
            else cout << s.top() << '\n';
        }
    }
    return 0;
}
