#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    for(int i=0; i<score.size(); ++i){
        int num = 1;
        double iAvg = (score[i][0]+score[i][1])/2.0;
        
        for(int j=0; j<score.size(); ++j){
            double jAvg = (score[j][0]+score[j][1])/2.0;
            if(jAvg>iAvg) num++;
        }
        answer.push_back(num);
    }
    
    return answer;
}
