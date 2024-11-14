#include<iostream>

using namespace std;

int solution(int a, int b, int n){
    int cnt=0;
    while(!(a>n || b>n)){
    	if(a<b) a+=b;
        else b+=a;
        cnt++;
    }
    return cnt;
}
    
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b, n;
        cin >> a >> b >> n;
        int answer = solution(a, b, n);
		cout << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
