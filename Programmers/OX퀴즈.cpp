#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (int i =0; i<quiz.size(); i++){
        stringstream ss(quiz[i]);
        vector<string> op;
        string element;
        while(getline(ss, element, ' ')){
            op.push_back(element);
        }
        if(op[1]=="+"){
            (stoi(op[0])+stoi(op[2]) ==stoi(op[4])) ? answer.push_back("O") : answer.push_back("X");
        }
        else{
            (stoi(op[0])-stoi(op[2]) ==stoi(op[4])) ? answer.push_back("O") : answer.push_back("X");
        }
    }
    
    return answer;
}
