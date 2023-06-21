#include <iostream>

#define MAX 1000001
using namespace std;

int Trading[MAX];
int purchases, price, maxPrice; // 구매 갯수, 구매 가격, 최대 가격

long long Solution(int N);
int main(){
    // 첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
    int T;
    cin >> T;
    for (int tc=1;tc<=T;tc++){
        // 초기화
        purchases=0, price=0, maxPrice=0;
        
        // 입력
        // 각 테스트 케이스 별로 첫 줄에는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고,
        int N;
        cin >> N;
        // 둘째 줄에는 각 날의 매매가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.
        // 각 날의 매매가는 10,000이하이다.
        for (int i=0; i<N; i++){
            // 입력받으면서 최대 가격인 날을 저장
            cin >> Trading[i];
            if(Trading[i]>maxPrice) maxPrice = Trading[i];
        }

        // 문제 풀이
        long long ans=Solution(N);

        //출력
        // 각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 이익을 출력한다.
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}

long long Solution(int N){
    // 1 2 3 4 5 1 10 이런 경우 Trading[i]>Trading[i+1]라고 5원에 팔면 안 됨
    // 전부 풀매수해서 10원에 파는 게 최대이득
    // 1 1 3 1 2 의 경우 앞의 두 날 사서 3원에 팔고 4번째 날 사서 5번째날 파는 게 최대이득
    // 1 9 1 8 1 7 1 6 이런 경우 1에 사서 다음날 팔고 다시 maxPrice구해서 파는 게 이득

    // 1. maxPrice날까지 풀매수(구매 갯수++; 구매 금액+=Trading[i]) & maxPrice날 전부 털기(maxprofit+=(구매갯수*파는 날의 가격)-구매금액)
    // 2. maxPrice초기화 후 현재 i값부터 끝까지 maxPrice 다시 찾기

    long long maxprofit=0; // 최대 이익(=answer)
    for (int i=0; i<N;i++){
        // 1. maxPrice의 인덱스까지 오면 들고 있는 거 다 털기
        // 2. left를 해당 인덱스로 저장하고, maxPrice=0, left 뒤부터 maxPrice를 다시 찾기
        if (Trading[i]==maxPrice){
            // 1. maxPrice의 인덱스까지 오면 들고 있는 거 다 털기
                //(maxprofit+=(구매갯수*파는 날의 가격)-구매금액)
                // 털었으니까 구매액, 구매 갯수 초기화
            maxprofit+=(purchases*Trading[i])-price;
            purchases = 0;
            price = 0;
            // 2. i+1번째부터 maxPrice=0, left 뒤부터 maxPrice를 다시 찾기
                // i가 지금 maxPrice라서 i 다음 값인 i+1로 해줘야 한다.
            maxPrice = 0;
            for (int j=i+1; j<N;j++){
                if(Trading[j]>maxPrice) maxPrice = Trading[j];
            }
        }
        // maxPrice가 아니라면 풀매수
        else {
            purchases++;
            price+=Trading[i];
        }
    }
    return maxprofit;
}