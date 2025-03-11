#include <string>
#include <vector>

using namespace std;

void dfs(int idx, const vector<int> &numbers, int sum, int target, int& answer){
    // 종료 조건
    if(idx==numbers.size()){
        if(sum==target){
            answer++;
        }
        return;
    }
    
    // 재귀 호출
    dfs(idx+1, numbers, sum+numbers[idx], target, answer);
    dfs(idx+1, numbers, sum-numbers[idx], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, numbers, 0, target, answer);
    
    return answer;
}
