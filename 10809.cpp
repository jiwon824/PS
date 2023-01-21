#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
    string S;
    cin >> S;
    int alpha[26]; //알파벳 개수 26개
    fill_n(alpha, 26, -1); // 아직 알파벳을 세기 전이므로 -1(포함되어 있지 않은 경우)로 초기화
    int alphaSize = sizeof alpha/sizeof alpha[0];

    // 배열에 알파벳 개수 입력하기
    for (int i=0; i<S.length(); i++){
        // S[i]가 a라면 S[i]-97==0이 된다. (a의 아스키코드가 97이기 때문)
        // alpha[0]=a alpha[1]=b ...
        // alpha[S[i]-97]<0 : 아직 이 알파벳이 나온 적 없다는 뜻
        if (alpha[S[i]-97]<0) alpha[S[i]-97] =i;
    }

    // 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력
    for (int i=0; i<alphaSize; i++){
        cout << alpha[i] << " ";
    } 
    
    return 0;
}