#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다. 괄호 문자의 개수는 최대 100,000이다. 
    string input;
    cin >> input;
    stack<char> s;
    int answer=0;

    for (int i=0; i<input.length(); i++){
        // '('+')'가 나오면 stack에 들어있는 ‘(’개수 만큼 ++
        if (input[i]=='(' && input[i+1]==')'){
            // stack.size() 는 현재 스택에 저장되어있는 데이터의 갯수를 반환
            answer += s.size();
            // input[i]와 input[i+1]을 하나로 처리해야함
            // input[i+1]을 ')' 인 경우로 한 번 더 세지 않도록 하기 위해 i++
            i++;
        }
        // '('가 나오면 stack에 ‘(’ push
        else if(input[i]=='(') s.push('(');
        // ')'가 나오면 막대기 하나가 끝난 것
        // pop으로 stack에서 ‘(’ 하나 없애고, answer+1
        else{
            s.pop();
            answer+=1;
        }
    }

    cout << answer << '\n';
    return 0;
}