#include <iostream>
#include <vector>

using namespace std;

vector<int> dwarf(9);
vector<int> picked;

bool isAnswer(){
    int sum=0;
    for(auto e:picked){
        sum+=e;
    }
    if(sum==100) return true;
    else return false;
}

void dfs(int curr_idx){

    if(curr_idx+1>9 || picked.size()>=7){
        if(picked.size()==7 && isAnswer()){
            for(auto e:picked){
                cout << e << '\n';
            }
        }
        return;
    }

    picked.push_back(dwarf[curr_idx]);
    dfs(curr_idx+1);

    picked.pop_back();
    dfs(curr_idx+1);
}

int main(){
    // input
    for(int i=0; i<9; ++i){
        cin >> dwarf[i];
    }

    // solution
    dfs(0);

    return 0;
}
