#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tc, n;
    long long DP[MAX] = {0, };

    cin >> tc;
    for (int t=1; t<=tc; t++){
        cin >> n;

        DP[1]=1;
        DP[2]=1;
        DP[3]=1;
        for (int i=4; i<=n; i++){
            DP[i] = DP[i-3] + DP[i-2];
        }
        cout << DP[n]<< '\n';
    }
    return 0;
}
