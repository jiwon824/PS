#include <string>
#include <vector>
#include <map>

using namespace std;

int myFind(int x, vector<int> &uf){
    if(uf[x]==x) return x;
    return uf[x] = myFind(uf[x], uf);
}

void myUnion(int x, int y, vector<int> &uf){
    x = myFind(x, uf), y = myFind(y, uf);
    if(x==y) return;
    uf[x]=y;
}

int solution(int n, vector<vector<int>> computers) {
    // uf 벡터 생성 및 초기화
    vector<int> uf(n);
    for(int i=0; i<n; i++){
        uf[i]=i;
    }
    
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(computers[i][j]==0) continue;
            myUnion(i, j, uf);
        }
    }
    
    // 그룹이 몇 개인지 알아보기 위함
    map<int, int> rootInfo; // {root, connection_cnt}
    for(int i=0; i<n; i++){
        rootInfo[myFind(i, uf)]++;
    }
    
    return rootInfo.size();
}
