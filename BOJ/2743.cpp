#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 알파벳으로만 이루어진 단어를 입력받아, 그 길이를 출력하는 프로그램
    string alpha;
    cin >> alpha;

    cout << alpha.length() << '\n';
    return 0;
}
