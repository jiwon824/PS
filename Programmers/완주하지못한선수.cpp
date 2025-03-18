#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 참가자 명단
    map <string, int> p;
    for(string name: participant){
        p[name]++;
    }
    // 완주자 명단
    map <string, int> f;
    for(string name: completion){
        f[name]++;
    }
    
    for(string name : participant){
        if(f.find(name)==f.end() || p[name]>f[name]){
            return name;
        }
    }
    
    return answer;
}
