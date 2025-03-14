#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool found = false;

// DFS + 백트래킹
void dfs(string from, vector<vector<string>> &tickets, vector<bool> &used, vector<string> route) {
    // 모든 항공권을 사용한 경우
    if (route.size() == tickets.size() + 1) {
        answer = route;  // 경로 저장
        found = true;    // 정답을 찾았음을 표시
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == from) {  // 사용하지 않은 티켓이면서 출발지가 일치하는 경우
            used[i] = true;
            route.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, used, route);
            if (found) return;  // 정답을 찾았다면 더 이상 탐색하지 않음
            used[i] = false;
            route.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 티켓을 알파벳 순으로 정렬
    sort(tickets.begin(), tickets.end());

    vector<bool> used(tickets.size(), false);
    vector<string> route;
    route.push_back("ICN");  // 시작점 고정

    dfs("ICN", tickets, used, route);

    return answer;
}
