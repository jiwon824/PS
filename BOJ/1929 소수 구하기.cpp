#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    bool PrimeNum[b];
    fill_n(PrimeNum, b+1, 1);
    PrimeNum[0]=false;
    PrimeNum[1]=false;

    for (int i=2;i<=b;i++){
        if (PrimeNum[i]==true) {
            //j를 1로 설정하면 i*1부터 시작. 그런데 이러면 소수인 자신도 false로 변경됨.
            //따라서 j=2부터 시작되어야 한다.
            for (int j=2; i*j<=b; j++){
                PrimeNum[i*j] = false;
            }
        }
        //처음 만난 PrimeNum[i]가 false면 검사하지 않고 넘어가기 
        else continue;
    }

//a~b이하 자연수 중 소수 출력
    for (int i=a; i<=b; i++){
        if (PrimeNum[i]==true) cout << i <<'\n';
    }

    return 0;
}
