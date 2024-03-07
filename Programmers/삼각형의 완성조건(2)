#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    // 1. 가장 긴 변이 sides 중 하나인 경우
    // - 나머지 변은 가장 긴 변보다 짧다.
    // - 나머지 변+짧은 변 > 가장긴 변이어야 한다.
    int longest_side = max(sides[0], sides[1]);
    int short_side = min(sides[0], sides[1]);
    
    for (int i =0 ; i<longest_side ; i++){
        if(i+short_side>longest_side) answer++;
    }
    
    // 2. 주어지지 않은 변이 가장 긴 변인 경우
    // - 주어진 변 중 큰 쪽보다 크거나 같은 수여야 한다.
    // - sides[0] + sides[1] > i
    for (int i=longest_side; sides[0] + sides[1]>i;i++){
        answer++;
    }
    
    return answer;
}
