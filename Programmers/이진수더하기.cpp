#include <iostream>
#include <string>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    // 두 문자열의 길이가 다른 경우 짧은 쪽 앞에 0을 넣어 길이를 맞춰준다.
    if (bin1.length()!=bin2.length()){
        int len_1 = bin1.length();
        int len_2 = bin2.length();
        if(len_1>len_2){
            for (int i=0;i<len_1-len_2;i++){
                bin2 = "0" + bin2;
            }
        }
        else{
            for (int i=0;i<len_2-len_1;i++){
                bin1 = "0" + bin1;
            }
        }
        
    }
    
    // 계산하는 부분
    int carry = 0;
    for(int i=bin1.length()-1; i>=0; i--){
        int tmp = (bin1[i]-'0') + (bin2[i]-'0') + carry;
        switch (tmp){
            case 0:
                answer = "0" + answer;
                carry=0;
                break;
            case 1:
                answer = "1" + answer;
                carry=0;
                break;
            case 2:
                answer = "0" + answer;
                carry=1;
                break;
            case 3:
                answer = "1" + answer;
                carry=1;
                break;
            default:
                break;
        }
    }
    if(carry==1) answer = "1" + answer;
    
    return answer;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << solution(s1, s2);
    return 0;
}