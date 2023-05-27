#include <iostream>

using namespace std;
#define MAX 1000001

int f(int n);
int main(){
    int n, test_num;
    long long dp[MAX] ={0, };
    long long sum[MAX] ={0, };

    //dp 배열 = f(n) 채우기
    //1부터 시작하니까 1,000,000까지 하려면 MAX 이하로 설정해야함
    //i가 1이라면 1의 배수인 칸을 모두 방문하면서 1 더하기 1*1, 1*2, 1*3, …, 1*1000001
    //i가 2라면 2의 배수인 칸을 모두 방문하면서 2 더하기 2*1, 2*2, 2*3, …, 2*1000001
    for (int i=1; i<=MAX; i++){ 
        for (int j=1; i*j<=MAX; j++){
            dp[i*j] += i;
        }
	}

//g(n) 누적합배열 채우기
    for (int i=1; i<=MAX; i++){
	    sum[i] = sum[i-1] + dp[i];
	}    

//testcase 숫자 입력받고, 입력 받은 만큼 저장된 sum값 g(n)을 출력
    cin >> test_num;
	for (int t=0; t<test_num; t++){
        cin >> n;
        cout << sum[n] << '\n';
    }    
	
    return 0;
}
