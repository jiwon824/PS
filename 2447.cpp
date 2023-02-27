// https://cryptosalamander.tistory.com/38
#include <iostream>
using namespace std;

void star(int i, int j, int N);
int main(){
    // 첫째 줄에 N이 주어진다. N은 3의 거듭제곱
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            star(i, j, N);
        }
        cout << '\n';
    }
    
    return 0;
}

void star(int i, int j, int N){
    // 가운데 좌표가 비어 있음
    // 비어 있는 좌표는 n=27일 때, (3,3) (3,4) (3,5) (4,3) (4,4) (4,5) (5,3) (5,4) (5,5)
    // (i / 3) % 3 == 1 && (j / 3 ) % 3 == 1
    if ((i / N) % 3 == 1 && (j / N ) % 3 == 1){
        cout << ' ';
    }
    else {
        if (N/3==0){
            cout << '*';
        }
        else {
            star(i, j, N/3);
        }
    }
}