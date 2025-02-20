#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1. 노란색의 가로 세로 완탐으로 구하기
    for(int i=1; i<=sqrt(yellow); i++){
        if(yellow%i==0){
            int yWight = yellow/i;
            int yHeight = i;
            
            // 2. 갈색의 가로세로는 노란색의 +2
            int width = yWight + 2;
            int height = yHeight + 2;
            
            // 3. [break] 전체에서 노란 타일을 빼면 갈색 타일의 갯수가 나와야 함.
            if((width*height -yellow)==brown){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}
