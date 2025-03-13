#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<bool> &visited, const vector<vector<int>> &computers){
    // 방문 체크
    visited[node]=true;
    
    // node 컴퓨터의 연결 정보를 쭉 살피기
    for(int i=0; i<computers[node].size(); i++){
        // node와 i컴퓨터의 연결정보
        int connection = computers[node][i];
        // 연결x || 이미 방문한 노드일 경우 재방문x
        if(connection==0 || visited[i]) continue;
        dfs(i, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        dfs(i, visited, computers);
        answer++;
    }
    return answer;
}
