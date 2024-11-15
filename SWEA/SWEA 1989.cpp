#include<iostream>

using namespace std;

int palindrome(string str){
    int len=str.length();
    for(int i=0; i<len; ++i){
    	if(str[i]!=str[len-i-1]) return 0;
    }
    return 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        cout << '#' <<  test_case << " " << palindrome(str) << '\n';
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
