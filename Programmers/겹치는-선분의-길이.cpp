#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    vector<pair<int,int> > v;
    for(size_t i=0; i<lines.size(); ++i){
        v.push_back({lines[i][0], 1}); // 시작점
        v.push_back({lines[i][1], -1}); // 끝점
    }
    
    sort(v.begin(), v.end());
    
    int overlap_cnt=0;
    int prev = v[0].first;
    for(size_t i=0; i<v.size(); ++i){
        // 선분이 2개 이상 겹친 구간
        if(overlap_cnt>=2){
            answer += v[i].first-prev;
        }
        overlap_cnt+=v[i].second;
        prev =v[i].first;
    }
    
    return answer;
}
