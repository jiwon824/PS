#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000+1
using namespace std;

vector<int> router;

int b_search(int N, int C);
// C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램
int main(){
    // 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다.
    int N, C;
    cin >> N >> C;

    // 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        router.push_back(tmp);
    }
    // 좌표 순서대로 정렬
    sort(router.begin(), router.end());

    // 공유기 간 최대거리 탐색, 출력
    cout << b_search(N, C);

    return 0;
}

int b_search(int N, int C){

    // left와 right는 이진탐색에서 mid를 구할 때 사용됨
    int left=1; // 첫 번째 공유기에서 첫 번째 공유기까지의 간격 (최소거리)
    int right=router[N-1]-router[0]; // 첫 번째 공유기에서 마지막 공유기까지의 간격(최대 거리)
    int result;

    // 이진 탐색 시작
    while(left<=right){
        // 공유기 설치에 필요한 변수들
        // 설치한 공유기 개수 (첫 번째 공유기는 설치하고 시작)
        int install_router = 1;
        // mid 간격마다 공유기 1개 설치
        int mid=(left+right)/2;
        // start, end는 mid 위치에 공유기 설치하기 위해 거리 재는 용도 변수
        int start = router[0];

        // 간격 확인하면서 공유기 설치하기 
        for (int i=1; i<N; i++){
            int end=router[i];

            // start->end까지의 거리가 mid보다 크거나 같으면 mid 위치에 공유기 설치 가능
            if (end-start >= mid){
                install_router+=1;
                // 공유기를 설치한 위치부터 mid 간격 뒤에 공유기를 설치해야 하니까
                // 방금 공유기를 설치한 end 위치로부터 간격을 세기 시작해야 한다.
                start=end;
            }
        }

        // 공유기 설치가 끝났으니까 공유기 개수 확인
        // 설치해야 할 개수보다 많이 설치되었다면 result에 저장한 후, 최대한 적게 설치하는 방법 찾기
        if (install_router >= C){
            result=max(result, mid);
            // left를 mid+1로 이동시키면 (left+right)/2 (=mid)가 증가
            // 더 큰 간격으로 공유기를 설치하기 때문에 install_router의 개수는 줄어듦
            left=mid+1;
        }
        // install_router < C
        // 설치해야 할 공유기 개수보다 적음->더 좁은 간격으로 설치하여 공유기를 더 많이 설치해야 함
        else right = mid-1;
    }
    return result;
}
