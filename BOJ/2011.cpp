#include <iostream>
#include <string>

#define MAX 5001
#define MOD 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string code;
    long long DP[MAX] = {0, };

    cin >> code;
    int len = code.length();

    // string 앞에 공백은 대체 왜 넣는 거지
    // 이거 없으면 안 돌아가던데 뭐지????
    code = " " + code;

    DP[0]=1;
    for (int i=1; i<=len; i++){
        int x = code[i]-'0'; // 문자열을 int로 바꿔주는 코드
        
        // i번째 숫자가 0보다 크면
        if (x > 0){
            DP[i] = (DP[i]+DP[i-1]) % MOD;
        }
        
        // i == 1:: i가 1인 경우는 위에 if에서 걸림
        // 0보다 큰 1번째 숫자 1~9는 위에서 처리된다.
        
        // code[i-1] == '0':: 이전의 숫자가 0인 경우.
        // 00, 01, 02 등등 전부 0, 1, 2와 동일 == 위에서 처리한 것들.
        // 처리했던 수를 다시 처리할 필요는 없으니 continue로 넘겨준다.
        if (i == 1 || code[i-1] == '0'){
            continue;
        }
    
        // 이전 숫자*10  + 현재 숫자
        // 26이라는 문자열을 2*10 + 6= 26 int형으로 저장하는 것
        x = (code[i-1] - '0') * 10 + (code[i] - '0');

        //저장한 수 x가 10~26 사이라면 경우의 수 추가
        if(x>=10 && x<=26){
            DP[i] = (DP[i] + DP[i-2]) % MOD;
        }

    }

    cout << DP[len] <<'\n';
    return 0;
}
