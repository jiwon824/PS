#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
    string S;
    cin >> S;
    int alpha[26]={0, }; //알파벳 개수 26개
    int alphaSize = sizeof alpha/sizeof alpha[0];

    // 배열에 알파벳 개수 입력하기
    for (int i=0; i<S.length(); i++){
        // S[i]가 a라면 S[i]-97==0이 된다. (a의 아스키코드가 97이기 때문)
        // alpha[0]=a alpha[1]=b ...
        alpha[S[i]-97] +=1;
    }

    // 출력
    for (int i=0; i<alphaSize; i++){
        cout << alpha[i] << " ";
    } 
    
    return 0;
}