// https://yoonsang-it.tistory.com/36
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// //a와 b를 비교하여, a>b의 결과를 반환한다.
bool desc(int a, int b){
    return a>b;
}

int main(){
    string N;
    cin >> N;
    int size=N.size();
    int arr[size+1];
    bool isZero = false;
    int sum=0;

    // string으로 입력받았던 것을 arr에 하나씩 숫자로 바꿔서 넣기
    for (int i=0; i<size; i++){
        arr[i]=N[i]-'0';
        sum+=arr[i];
        if(arr[i]==0) isZero=true; // 0이 안에 있으면 10의 배수를 만들 수 있음
    }

    // 0이 없어서 10의 배수를 만들지 못하거나 주어진 수의 각자리 합이 3의 배수가 아니면
    // 30의 배수를 만들지 못하니까 -1 출력
    if (!isZero || sum%3!=0) cout << "-1" << '\n';
    // 위에서 걸러지지 않았으면 30의 배수를 만들 수 있음
    // 30의 배수가 되는 가장 큰 값은 주어진 수를 내림차순으로 정렬해주면 된다.
    else{
        sort(arr, arr+size, desc);
        for (int i=0; i<size; i++){
            cout << arr[i];
        }
        cout << '\n';
    }

    return 0;
}
