#include<iostream>
#include<string>

using namespace std;

void solution(int n){
	for(int i=1; i<=n; ++i){
    	string str = to_string(i);
        string threeSixNine = "";
        for(int j=0; j<str.length(); ++j){
        	int singleNum=str[j]-'0';
            if(singleNum!=0 && singleNum%3==0) threeSixNine = threeSixNine + '-';
        }
        if(threeSixNine.length()==0) cout << i << " ";
        else cout << threeSixNine << " ";
    }
}
int main(int argc, char** argv)
{
	int num;
    cin >> num;
	solution(num);    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
