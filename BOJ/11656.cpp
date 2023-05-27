#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000보다 작거나 같다.
    string S;
    cin >> S;
    string suffix[S.length()]; //접미사 배열

    for (int i=0; i<S.length(); i++){
        for (int j=i;j<S.length();j++){
            suffix[i]+=S[j];
        }
    }

    // 사전순 정렬
    sort(suffix, suffix+S.length());

    //출력
    for (int i=0;i<S.length();i++){
        cout << suffix[i] <<'\n';
    }
    return 0;
}
