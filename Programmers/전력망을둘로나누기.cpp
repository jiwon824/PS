#include <string>
#include <vector>
#include <cmath>

using namespace std;

int myFind(int x, vector<int>& uf){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x], uf);
}

void myUnion(int x, int y, vector<int>& uf){
    x = myFind(x, uf), y = myFind(y, uf);
    if(x==y) return;
    uf[x]=y;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int remove=0; remove<wires.size(); remove++){
        // uf배열 생성 및 초기화
        vector<int> uf(n+1);
        for(int v=0; v<=n; ++v){
            uf[v]=v;
        }
        
        // 간선 연결
        for(int connect=0; connect<wires.size(); connect++){
            // 연결하지 않을 간선은 건너뜀
            if(connect==remove) continue;
            int a = wires[connect][0], b = wires[connect][1];
            myUnion(a, b, uf);
        }
        
        // 트리에 연결된 정점의 개수
        int root1=myFind(uf[1], uf);
        int cnt1=0, cnt2=0;
        for(int v=1; v<=n; v++){
            if(myFind(uf[v], uf)==root1) cnt1++;
            else cnt2++;
        }
        answer = min(answer, abs(cnt1-cnt2));
    }
    
    return answer;
}
