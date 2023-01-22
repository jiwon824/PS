#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 첫째 줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S가 주어진다. S의 길이는 100을 넘지 않는다.
    string S;
    getline(cin, S);

    for (int i=0; i<S.length(); i++){
        //ASCII (small:97~122, capital:65~90, Num:48~57, space:32)
        if ((S[i]>='a'&& S[i]<='m')||(S[i]>='A'&& S[i]<='M')) S[i]+=13;
        else if ((S[i]>='n'&& S[i]<='z')||(S[i]>='N'&& S[i]<='Z')) S[i]-=13;
    }

    cout << S <<'\n';
    return 0;
}