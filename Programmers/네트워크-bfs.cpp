#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<bool> &visited, const vector<vector<int>> &computers){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<computers[curr].size(); i++){
            int connection = computers[curr][i];
            // 연결이 없거나 이미 방문한 노드는 재방문x
            if(connection==0 || visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        // 방문한 노드는 재방문하지 않는다.
        if(visited[i]) continue;
        answer++;
        bfs(i, visited, computers);
    }
    return answer;
}
