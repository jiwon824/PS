#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
int main(){
    int a, b;//입력 받을 두 수. a, b는 10,000이하의 자연수
    cin >> a >> b;

    //최대공약수
    cout << gcd(a, b) << '\n';
    //최소공배수
    cout << lcm(a, b) << '\n';
    return 0;
}

int gcd(int a, int b){
    while (a != 0 and b != 0){ //두 수 중 하나라도 0이 되면 종료
        if (a > b) a= a % b; //나머지 연산
		else b = b % a;
    }
    return a + b;    
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}