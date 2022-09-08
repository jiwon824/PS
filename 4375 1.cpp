#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num, answer, n;

    while(!cin.eof()){
        num = 1;
        answer = 1;
        cin >> n;
        if (cin.eof()) break;

        while(num%n != 0){
            num = num*10 + 1;
            num %= n;
            answer += 1;

        }
        cout << answer << '\n';
    }
    
    return 0;
}
