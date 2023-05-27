#include <iostream>

using namespace std;

bool IsPrime(int n);
int main(){
    int test_num, input_num;
    int ans = 0;
    cin >> test_num;

    for (int i=0; i<test_num;i++){
        cin >> input_num;
        if(IsPrime(input_num)) ans++; //소수면 ans+1
    }
    cout << ans << '\n';

    return 0;
}

//소수인지 아닌지 판별하는 함수
bool IsPrime(int n){
    if (n==1) return false; //1은 소수가 아님
    for (int i=2; i<n; i++){ //2부터 자기자신 전까지의 수로 나누어지면 소수 아님
        if (n%i==0) return false;
    }
    //앞의 조건들에서 걸러지지 않았으면 1이 아니면서 1, 자신으로만 나누어짐=소수
    return true;
}
