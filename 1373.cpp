#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string binary = "";
    cin >> binary;
    // 3자리씩 끊을 수 있게 앞에 0추가
    while (binary.length()%3){
        binary = '0' + binary;
    }

    // 2->8
    for (int i=0; i<binary.length(); i+=3){
        // 0번째: 2^2=4 곱하기, 1번째는 2^1=2 곱하기, 2번째는 2^0=1 곱하기
        int octal = (binary[i]-'0')* 4 + (binary[i+1]-'0')* 2 + (binary[i+2] - '0')* 1;
        cout << octal;
    }

    return 0;
}