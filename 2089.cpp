#include <iostream>
#include <stack>

using namespace std;

int main(){
    long long N;
    cin >> N;
    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    stack<int> binary;
    while(N !=0){
        // 나눠야 할 값이 짝수인 경우
        // 짝수인 경우 2로 나누면 나머지가 0이기 때문에 stack에 0저장
        if (N%2==0){
            binary.push(0);
            N = -(N/2);
        }
        else{
            // 홀수인 경우 2로 나누면 나머지 1발생 -> stack에 1저장
            // 홀수면서 음수인 경우
            if (N<0){
                binary.push(1);
                N = (-N+1)/2;
            }
            // 홀수면서 양수인 경우
            else{
                binary.push(1);
                N = -(N/2);
            }
        }
    }

    while (!binary.empty()){
        cout << binary.top();
        binary.pop();
    }

    return 0;
}