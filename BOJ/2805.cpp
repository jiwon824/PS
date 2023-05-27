#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;

int N; // (1 ≤ N ≤ 1,000,000)
long long M; // (1 ≤ M ≤ 2,000,000,000)
long long treeHeight[MAX];

int main(){
    // 나무의 수 N과 가져가려고 하는 나무의 길이 M
    cin >> N >> M;
    long long maxi=0;
    // 둘째 줄에는 나무의 높이가 주어진다.
    for (int i=0; i<N; i++){
        cin >> treeHeight[i];
        maxi=max(maxi, treeHeight[i]);
    }
    // 나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다.
    // 0<=높이<=1,000,000,000
    long long sum=0; //나무의 높이의 합 sum>=M이 되면 ans에 저장
    long long left=0, mid, right=maxi, H=0; // H=ans 절단기에 설정할 수 있는 높이의 최댓값
    while (left<=right){
        mid=(left+right)/2;
        for (int i=0;i<N;i++){
            if(treeHeight[i]-mid>0) sum+=treeHeight[i]-mid;
        }
        // 적어도 M미터의 나무를 확보했다면
        // 더 큰 길이를 설정해도(=나무를 조금 덜 잘라도) M미터를 만족시킬 수 있는지 확인
        if (sum>=M){
            H=max(H, mid);
            left=mid+1;
            sum=0;
        }
        // sum<M -> M미터의 나무를 확보하지 못했음
        // 더 작은 길이로 설정해서 M미터를 만족시키는 수가 있는지 확인
        else {
            right=mid-1;
            sum=0;
        }

    }
    cout << H << '\n';
    return 0;
}
