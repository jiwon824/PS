#include <iostream>

#define MAX 10001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // +++ 변수 선언 +++
    int N; // 첫 줄에 N개의 수가 주어짐 (1 ≤ N ≤ 10,000,000)
    //N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수
    int Arr[MAX] = {0, }; //초기화 꼭 해줘야 함

    cin >> N;
    // +++ 입력 +++
    for (int i=0; i<N; i++){
        int inputNum;
        cin >> inputNum;
        Arr[inputNum] +=1;
    }

    // +++ 출력 +++
    for (int i=0; i<MAX; i++){
        for (int j=0; j<Arr[i];j++){
            cout << i << '\n';
        }
    }
    return 0;
}
