#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
    string BNum= "";
    int B;
    cin >> BNum >> B;
    // BNum을 10진수로 변환
    int ans = 0;
    // 1의 자리는 1의자리숫자*(B^1)
    // 10의 자리는 10의자리숫자*(B^2) ...
    // 1101_(2) = 1*2^3 + 1*2^2 + 1*2^0 = 8+4+1 = 13_(10)
    int p = BNum.length()-1; //B^p
    for (int i=0; i<BNum.length();i++){
        if (BNum[i]>='A' && BNum[i]<='Z'){
            ans += (BNum[i]-'A'+10)*((int)pow(B, p));
        }
        else {
            ans += (BNum[i]-'0')*((int)pow(B, p));
        }
        p--;
    }
    cout << ans << '\n';
    return 0;
}
