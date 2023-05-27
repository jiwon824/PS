// https://cryptosalamander.tistory.com/39
#include <iostream>

using namespace std;

// n개의 원판을 start에서 to로 옮김. bypass를 거쳐서
void hanoi(int n, int start, int to, int bypass){
    // 옮겨야 할 원판이 1개(마지막 원판)라면 어디서 어디로 옮겼는지 출력하고 끝내기
    if (n==1){
        cout << start << " " << to << '\n';
    }
    // 옮겨야 할 원판이 여러 개라면
    else{
        // 먼저 n-1개의 원판을 3번 장대를 거쳐 2번 장대로 옮기고,
        // 1번 장대에 있는 가장 큰 크기의 원판을 3번 장대로 옮긴 후,
        // 2번 장대에 있는 n-1개의 원판을 1번 장대를 거쳐 3번 장대로 올려 놓는 과정이다. 
        hanoi(n-1, start, bypass, to);
        cout << start << " " << to <<'\n';
        hanoi(n-1, bypass, to, start);
    }
}

int main(){
    // 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.
    int N;
    cin >> N;

    // 첫째 줄에 옮긴 횟수 K를 출력한다.
    // 1<<N==2^N 하노이 탑에서 원판 갯수가 N일 때, 최소 이동 횟수는 2^N-1번이다.
    cout << (1<<N)-1 << '\n';
    // 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데,
    // 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻
    hanoi(N, 1, 3, 2);

    return 0;
}
