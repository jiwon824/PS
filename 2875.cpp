#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    // 여학생 수를 2로 나눈 것과 남학생 수를 비교하여 더 작은 쪽으로 팀을 만들기
    int team = min(N/2, M);
    // N, M에 팀짜고 남은 사람의 수 저장하기
    N -= team*2;
    M -= team;
    // 남은 인원 수가 인턴에 가야할 사람의 수보다 적다면
    // team을 하나씩 쪼개서 개별 인원으로 만들기
    while (N+M<K){
        team-=1;
        N+=2;
        M+=1;
    }
    cout << team << '\n';
    return 0;
}