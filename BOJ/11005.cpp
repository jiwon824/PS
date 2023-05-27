#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
    long long N;
    int B;
    cin >> N >> B;
    // 10진법 수 N을 B진법으로 변환
    string BNum= "";
    while (N > 0){
        int r = N % B;
        // A~Z인 경우. r=22라고 하면 10까지는 숫자로 표현되니까 10을 빼주고
        // 12번째 알파벳을 출력하면 됨
        if(r>=10) BNum += (char)r -10 +'A';
        // 그냥 (char)r 이라고 하면 0~9에 해당하는 아스키코드가 저장됨
        else BNum += (char)r + '0';
        N/=B;
    }
    reverse(BNum.begin(),BNum.end());
    cout << BNum << '\n';
    return 0;
}
