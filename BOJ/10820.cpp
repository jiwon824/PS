#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램
    string input;
    while(getline(cin, input)){
        // 문자열의 길이는 100을 넘지 않는다(1 ≤ N ≤ 100).
        //ASCII (small:97~122, capital:65~90, Num:48~57, space:32)
        int small=0, capital=0, Num=0, space=0;
        for (int i=0; i<input.length();i++){
            if (input[i]>='a' && input[i]<='z') small++;
            else if (input[i]>='A' && input[i]<='Z') capital++;
            else if (input[i]>='0' && input[i]<='9') Num++;
            else space++;
        }
        //소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력
        cout << small << ' ' << capital << ' ' << Num << ' ' << space << '\n';
    }
    return 0;
}
