#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int sum=0;

    //난쟁이 9명의 키 저장 배열+입력
    int dwarf[9];
    for (int i=0;i<9;i++){ 
        cin >> dwarf[i];
        sum+=dwarf[i];
    }

    //정렬
    sort(dwarf, dwarf+9);

    //9명 중 2명을 선택
    for (int i=0;i<9;i++){
        for (int j=i+1;j<9;j++){
            if (sum-(dwarf[i]+dwarf[j])==100){
                for (int k=0;k<9;k++){
                    if (i==k||j==k) continue;
                    cout << dwarf[k] << '\n';
                }
                return 0;//정답이 여러 개인 경우 하나의 답안만 제출하고 프로그램을 종료하기 위해
            }
        }
    }
    return 0;
}
