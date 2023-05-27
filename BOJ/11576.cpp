#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// A진법으로 나타낸 수를 10진법으로 변환하였을 때의 값은 양의 정수이며 220보다 작다.
// AToDecimal(A진법, 숫자, 자릿수);
int AToDecimal(int A, int ANum, int i);
// AToDecimal(B진법, 10진수 숫자);
stack<int> DecimalToB(int B, int Decimal);
int main(){
    // A진법으로 나타낸 수를 B진법으로 변환하여 출력
    // 입력의 첫 줄에는 진법 A와 진법 B가 공백을 구분으로 주어진다. A와 B는 모두 2이상 30이하의 자연수
    int A, B;
    cin >> A >> B;
    // 입력의 두 번째 줄에는 A진법으로 나타낸 숫자의 자리수의 개수 m(1 ≤ m ≤ 25)
    int m;
    cin >> m;
    // 세 번째 줄에는 A진법을 이루고 있는 숫자 m개가 공백을 구분으로 **높은 자릿수부터 차례대로** 주어진다.
    // 각 숫자는 0이상 A미만임이 보장된다. 또한 수가 0으로 시작하는 경우는 존재하지 않는다.
    int decimal=0;
    for (int i=m-1;i>=0;i--){
        int ANum;
        cin >> ANum;
        decimal += AToDecimal(A, ANum, i);
    }
    
    //10진법 -> B진법으로 변환
    stack<int> BNum;
    BNum = DecimalToB(B, decimal);

    // 출력
    for (int i=0; !BNum.empty(); i++){
        cout << BNum.top() << " ";
        BNum.pop();
    }
    return 0;
}

int AToDecimal(int A, int ANum, int i){
    // 2745의 B진법 Num을 10진수로 변환 참고
    // 1의 자리는 1의자리숫자*(A^1)
    // 10의 자리는 10의자리숫자*(A^2) ...
    // 1101_(2) = 1*2^3 + 1*2^2 + 1*2^0 = 8+4+1 = 13_(10)
    return ANum *((int)pow(A, i));
}

stack<int> DecimalToB(int B, int Decimal){
    stack<int> BNum;
    while (Decimal > 0){
        int r = Decimal % B;
        BNum.push(r);
        Decimal/=B;
    }

    return BNum;
}
