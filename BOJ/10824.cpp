#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)
    long long A, B, C, D;
    long long AB, CD;
    cin >> A >> B >> C >> D;

    //AB=A*B의 자릿수+B
    int digits=1;
    for (int i=B; i>=10;i/=10){
        digits*=10;
    }
    AB=A*(10*digits)+B;
    
    //CD=C*D의 자릿수+D
    digits=1; // digits 초기화
    for (int i=D; i>=10;i/=10){
        digits*=10;
    }
    CD=C*(10*digits)+D;

    cout << AB+CD << '\n';
    return 0;
}
