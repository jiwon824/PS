#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // 첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)
    int n;
    cin >> n;
    vector<int> time;
    int sum = 0;
    for(int i = 0; i<n;i++){
        int t;
        cin >> t;
        time.push_back(t);
    }
    sort(time.begin(), time.end());

    for (int i = 0; i < n ;i++){
        // 1+(1+2)+(1+2+3)+(1+2+3+3)+(1+2+3+3+4)
        // p[1]*n +p[2]*(n-1)+…+p[n]*1
        sum += time[i]*(n-i);
        
    }
    cout << sum << '\n';

    return 0;
}