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
            //합이 100이 되는 수를 찾으면 i, j번째 원소 삭제
            if (sum-(dwarf[i]+dwarf[j])==100){
                for (int k=0;k<9;k++){
                    if (i==k||j==k) continue;
                    cout << dwarf[k] << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}
