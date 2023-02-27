// https://ansohxxn.github.io/boj/2448/
#include <iostream>
#include <cstring>
using namespace std;

char star[3072][6144];//세로 N, 가로 2N-1

void printStar(int x, int y, int n);
int main(){
    int N;
    cin >> N;
    memset(star, ' ', sizeof(star));

    printStar(0, N - 1, N);//x좌표, y좌표, N값

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            
        }
        cout << '\n';
    }
    return 0;
}

void printStar(int x, int y, int n){
    //기본 별찍기
    //   *
    //  * *
    // *****
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
	}

}