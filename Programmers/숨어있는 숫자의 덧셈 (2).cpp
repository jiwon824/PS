#include <iostream>

using namespace std;

int main(){
    string my_string;
    cin >> my_string;
    int answer = 0;
    int num =0;
    for (int i=0;i<my_string.length();i++){
        if (isdigit(my_string[i])){
            num = num*10 + my_string[i]-'0';
        }
        else{
            answer += num;
            num = 0;
        }
    }
    answer += num;
    cout << answer <<"\n";
    return 0;
}