#include<iostream>

using namespace std;

const int MAX_N=10;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        
        int pascal[MAX_N+1][MAX_N+1];
        // 1로 배열 초기화
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                pascal[i][j]=1;
            }
        }
        
        // line0, 1은 1로만 채워짐
        for(int i=2; i<n; ++i){
            for(int j=1; j<i; ++j){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        
        // [output]
        cout << '#' << test_case << '\n';
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i; ++j){
                cout << pascal[i][j] << " ";
            }
            cout << '\n';
        }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
