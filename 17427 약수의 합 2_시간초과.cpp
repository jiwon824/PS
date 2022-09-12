#include <iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;


int F(int n);
int main(){
    int n;
    int sum = 0;

    cin >> n;
    //n보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값 g(n)
    for (int i=1; i<=n; i++){ 
        sum += F(i);
    }

    cout << sum << '\n';

    return 0;
}

int F(int n){
    vector<int> divisor;
    int sum = 0;

    //n제곱근까지 약수짝(10의 약수라면 2, 5가 짝인 셈) 벡터에 넣기
    for (int i=1; i<=sqrt(n); i++){
        if(n%i==0) {
            divisor.push_back(i);
            divisor.push_back(n/i);
        }
    }

    divisor.erase(unique(divisor.begin(), divisor.end()), divisor.end());

    //벡터 요소들 합하기
    for (int i=0; i<divisor.size(); i++){
        sum += divisor[i];
    }

    return sum;
}