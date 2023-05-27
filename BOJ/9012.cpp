#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string input);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; // 입력 데이터의 수
    cin >> T;
    // 하나의 괄호 문자열의 길이는 2 이상 50 이하
    for (int tc=0; tc<T; tc++){
        string input; // '(())())'
        cin >> input;

        // solution() 호출 짝이 맞는지 검사하기
        if(solution(input)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}

bool solution(string input){
    stack<char> tmp; // 괄호 짝이 맞는지 확인할 때 사용할 stack

    for (int i=0; i<input.length(); i++){
        if (input[i] == '('){
            tmp.push(input[i]);
        }
        else {
            if (!tmp.empty()){
                tmp.pop();
            }
            else{
                // 닫는 괄호인데 스택이 비어있으면
                // ')(())', '()())()' 이런 식인 것 -> false
                return false;
            }
        }
    }
    
    // tmp가 비어있다면 짝이 맞는것 true
    // tmp에 pop되지 못한 요소가 있다면 짝이 맞지 않는 것 false
    return tmp.empty();
}
