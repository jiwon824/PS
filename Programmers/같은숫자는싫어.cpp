#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> stk;
    stk.push(arr[0]);
    answer.push_back(arr[0]);
    
    for(int i=1; i<arr.size(); i++){
        if(stk.top()==arr[i]) continue;
        stk.push(arr[i]);
        answer.push_back(arr[i]);
    }

    return answer;
}
