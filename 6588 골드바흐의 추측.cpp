#include <iostream>
#include <cmath>

using namespace std;
#define MAX 1000001

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    bool wrong=true;
    //int max, min;//max는 큰 소수부터 작아지는 수, min은 작은 소수부터 커지는 수

    //소수 배열 PrimeNum 배열 만들기
    bool PrimeNum[MAX];
    fill_n(PrimeNum, MAX+1, 1);
    PrimeNum[0]=false;
    PrimeNum[1]=false;

    for (int i=2;i<=MAX;i++){
        if (PrimeNum[i]==true) {
            //j를 1로 설정하면 i*1부터 시작. 그런데 이러면 소수인 자신도 false로 변경됨.
            //따라서 j=2부터 시작되어야 한다.
            for (int j=2; i*j<=MAX; j++){
                PrimeNum[i*j] = false;
            }
        }
        //처음 만난 PrimeNum[i]가 false면 검사하지 않고 넘어가기 
        else continue;
    }

//n을 입력받고, 두 홀수 소수의 합으로 표현하는 부분
    while (1){
        cin >> n;
        //n은 짝수여야 함
        if (n==0) break;

        //n과 n-num[i], num[i]를 생각하면서 코드 짜기.
        //n-3부터 본다는 생각이 애초에 n-num[i]를 본다는 생각이 아니었을까
        for (int i= 3;i<n;i++){//i는 n부터 3까지 1씩 줄어듦.
            if (PrimeNum[i]==false) continue; //i가 소수일 때만 반복문 속 명령 실행
            //PrimeNum[n-i]가 소수라면 PrimeNum[i]+PrimeNum[n-i]=n이 된다.
            if (PrimeNum[n-i]==true){
                cout << n << " = " << i << " + " << n-i <<'\n';
                wrong=false;
                break;
            }
        }
        //성립하는 게 없으면
        if(wrong) cout << "Goldbach's conjecture is wrong.";
    }

    return 0;
}