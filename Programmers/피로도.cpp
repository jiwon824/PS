#include <string>
#include <vector>

using namespace std;

int len = 0;
int answer = -1;
bool visited[8] = {false, };
vector<int> exploringOrder;

// 주어진 순서로 돌 경우, 몇 개의 던전을 돌 수 있는지 반환
int explore(int k, const vector<vector<int>>& dungeons){
    int clear = 0;
    for(int curr : exploringOrder){
        int require = dungeons[curr][0];
        
        // 현재 피로도가 최소 필요 피로도보다 작은 경우
        if(k<require) break;
        
        int expend = dungeons[curr][1];
        k -= expend;
        clear++;
    }
    return clear;
}

// 던전 도는 순서 순열 만들기
void backtracking(int curr, int k, const vector<vector<int>>& dungeons){
    // 종료 조건
    if(curr==len){
        answer=max(answer, explore(k, dungeons));
        return;
    }
        
    // 재귀
    for(int i=0; i<len; i++){
        if(visited[i]) continue;
        
        exploringOrder.push_back(i);
        visited[i] = true;
        
        backtracking(curr+1, k, dungeons);
        
        exploringOrder.pop_back();
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    len = dungeons.size();
    
    backtracking(0, k, dungeons);
    
    return answer;
}
