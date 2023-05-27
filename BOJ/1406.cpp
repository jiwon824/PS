#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 영어 소문자만 입력 가능한 에디터
    // 커서를 기준으로 왼쪽 스택과 오른쪽 스택 선언
    stack <char> leftStack;
    stack <char> rightStack;
    // 첫째 줄에는 초기에 편집기에 입력되어 있는 문자열
    string inputString;
    cin >> inputString;
    // 초기에 편집기에 입력을 받으면 커서가 문자열 맨 뒤에 있음(커서 기준 왼쪽에 문자)
    for (int i=0;i<inputString.length();i++){
        leftStack.push(inputString[i]);
    }
    // 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)
    int commandInt;
    cin >> commandInt;
    // 셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.
    char commandChar;
    for (int i =0; i<commandInt; i++){
        // L D B P
        cin >> commandChar;
        // 커서를 왼쪽으로 한 칸 옮김
        // 왼쪽 스택에 아이템이 있다면 !leftStack.empty(), 
        if (commandChar == 'L'){
            // 이미 커서가 제일 왼쪽에 있음
            if (leftStack.empty()) continue;
            else {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        }

        else if (commandChar == 'D'){
            // 이미 커서가 제일 오른쪽에 있는 것
            if (rightStack.empty()) continue;
            else {
                leftStack.push(rightStack.top());
                rightStack.pop();
            }
        }
        else if (commandChar == 'B'){
            // 왼쪽에 삭제할 문자 없음
            if (leftStack.empty()) continue;
            // 왼쪽 문자 삭제
            else leftStack.pop();
        }
        // commandChar == 'P'
        else{
            char addChar;
            cin >> addChar;
            leftStack.push(addChar);
        }
    }

    // 출력
    while(!leftStack.empty()){
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
    while(!rightStack.empty()){
        cout << rightStack.top();
        rightStack.pop();
    }
    return 0;
}
