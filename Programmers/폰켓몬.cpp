#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    // map에 추가하기
    map<int,int> m;
    for(int num : nums){
        m[num]++;
    }
    
    int curr = 0, maxChoose = nums.size()/2;
    for(auto e : m){
        if(curr>=maxChoose) break;
        curr++;
        answer++;
    }
    
    return answer;
}
