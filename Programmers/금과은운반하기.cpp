#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// mid 시간 안에 목표 광물 kg을 달성할 수 있는지
bool checkMidValue(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid){
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalMineral = 0; // gold+silver 
    
    for(int i=0; i<g.size(); i++){
        // 트럭이 처음 광물을 옮기는 데에 드는 시간은 t[i]
        // 그 후 광물을 옮기는 데에 드는 시간은 2*t[i] (왕복 해야 함)
        int oneWay = t[i];
        
        // 트럭이 몇 번 광물을 옮길 수 있는가
        long long moveCnt = mid/(oneWay*2);
        if (mid % (oneWay*2) >= oneWay) moveCnt++;
        
        // 옮길 수 있는 광물의 총량 (최대 운반 가능 량 w[i] * 최대 운반 가능 횟수 moveCnt)
        long long transferableMineral = w[i] * moveCnt;
        
        totalGold += min((long long)g[i], transferableMineral);
        totalSilver += min((long long)s[i], transferableMineral);
        totalMineral += min((long long)g[i]+s[i], transferableMineral);
    }
    
    // [return]
    if(totalGold>=a && totalSilver>=b && totalMineral >=a+b) return true;
    else return false;
    
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long lo = 0, hi = 10e14 * 3;
    long long answer = hi;
    
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        if(checkMidValue(a, b, g, s, w, t, mid)){
            answer = min(answer, mid);
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return answer;
}
