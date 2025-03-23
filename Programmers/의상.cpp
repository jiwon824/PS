#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m; //{type, cnt}
    for(auto cloth : clothes){
        m[cloth[1]]++;
    }
    
    for(auto e : m){
        // 안 입는 경우를 포함하기 위해 +1
        answer *= e.second+1;
    }
    
    // 아무것도 안 입는 경우를 빼줌
    answer-=1;
    return answer;
}
