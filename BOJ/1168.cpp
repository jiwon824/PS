#include <iostream>
#include <vector>
using namespace std;

// 높이가 17인 포화이진트리의 맨 아래층 리프 개수는 (1 << 17) = 131,072개 이고,
// 총 노드의 개수는 맨 아래층 리프개수의 약 두배인 262144-1 = 262,143 (루트 노드는 하나니까 -1 해줌)
int segment[300000];


int init(int start, int end, int node);
int update(int start, int end, int node, int del);
int next_kill(int start, int end, int node, int order);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    init(1, N, 1); // init(int start, int end, 루트노드);
    
    int index=1;

    // 요세푸스+출력
    cout << "<";
    for (int i = 0; i < N; i++){
        // 몇 번째 사람을 죽여야 하는지 구하기
        int alive= N - i; // 살아있는 사람의 수
        index+=K-1;

        // N=7, K=3이면 {1,2,3,4,5,6,7} 7개의 수들 중 3번째 수인 3을 제거
            // index = index+K-1 == 1+3-1==3
            // (index%alive==0) 3%7=1 -> 아님
            // (index>alive) == 3>7 -> 아님
        // 그 다음에는 {1,2,4,5,6,7} 6개의 수들 중 5번째 수인 6을 제거
            // ==없어진 3 자리에서부터 3번째 사람
            // index =3+3-1
            // (index%alive==0) 5%6=5 -> 아님
            // (index>alive) == 5>6 -> 아님
            // -> index값 변경 없이 index=5
        // 그 다음에는 {1,2,4,5,7} 5개의 수들 중 2번째 수인 2을 제거
            // ==없어진 6 자리에서부터 3번째 사람
            // index =5+3-1=7
            // (index>alive)니까 7%5=2 -> 2번째 사람 제거 가능
        if (index % alive == 0) index=alive;
        else if (index > alive) index%=alive;

        // 죽일 사람 구하기
        // next_kill(int start, int end, int node, int order)
        // 1~N까지의 수 중 루트노드(=1)부터 시작해서 order(=index)번째 사람 찾기
        int num = next_kill(1, N, 1, index);

        // 해당 번호 없애기
        update(1, N, 1, num);
        
        // 마지막 반복 이라면 num만 출력해야함
            //i<N까지 반복이니까 N-1까지 반복하는 것
        if(i==N-1) cout << num;
        // 그게 아니라면 num, 를 출력해야함
        else cout << num << ", ";
    }
    cout << ">";
    return 0;
}


// (시작, 끝, 루트노드)
int init(int start, int end, int node){
    // start와 end의 위치가 일치하면(=노드의 범위가 1인 리프노드가 된다면) 1을 넣어준다.
    // 그 번호에 있는 사람이 살아 있음을 의미(죽으면 0으로 바꿀 것)
    if (start == end) return segment[node] = 1;

// arr[12] = {3, 5, 6, 7, 2, 9, 4, 5, 2, 8, 1, 5}라고 했을 때,
// 첫 init(2 * node, start, mid)에 의해 들어가는 인자를 숫자로 표현해보면, init(2, 0, 5)
// 즉, 1번 루트 노드의 왼쪽 자식(2번 노드)에는 arr[0~5] ( = arr[start~mid) )값이 들어간다는 것이다.

// init(2 * node + 1, mid+1, end)에는 init(3, 6, 11)과 같이 들어간다.
// 즉, 1번 루트 노드의 오른쪽 자식(3번 노드)에는 arr[6~11]] ( = arr[mid+1~end) )값이 들어간다는 것이다.
    // 리프노드가 아니라면 현재노드에 왼쪽노드(init)+오른쪽 노드(init) 저장
    // 왼쪽 자식 init(start, mid, 2 * node)을 루트노드로 하는 서브트리
    // 오른쪽 자식 init(mid + 1, end, 2 * node + 1)을 루트노드로 하는 서브트리
    int mid = (start+end)/2;
    return segment[node] = init(start, mid, 2 * node) + init(mid + 1, end, 2 * node + 1);
}

//(시작, 끝, 현재노드, 제거번호)
int update(int start, int end, int node, int del){
    //현재 노드의 값을 1 감소시키기
    segment[node]--;
    // 리프노드에 노착하면 탈출
    if (start == end) return 0;
    else
    {
        int mid = (start + end)/2;
        //제거할 번호가 왼쪽에 있다면 왼쪽 노드로 가고, 아니면 오른쪽 노드로 가기
        if (del <= mid) return update(start, mid, 2 * node, del);
        else return update(mid + 1, end, 2 * node + 1, del);
    }
}

// 다음에 죽일 사람 번호 리턴 (시작, 끝, 현재노드, order번째 번호)
int next_kill(int start, int end, int node, int order){
    if (start == end) return start;
    int mid = (start+end)/2;

/*
https://velog.io/@gkak1121/백준-요세푸스-문제2-1168-번
구현할 때 주의할 것은 왼쪽 노드를 삭제하는 것과 오른쪽 노드를 삭제할 때 Index를 바라보는 방식이 다르다는 것
예를 들어, 첫 사진에서 5의 경우는 루트에서 오른쪽 노드로 흐르는데, 이는 1~4 다음으로 나오는 첫 번째 인덱스라는 의미이다.
이를 위해서 오른쪽으로 흐를 때에는 5를 그대로 사용하지 않고, 오른쪽으로 흐른 뒤 1번째 인덱스를 찾도록 해줘야 한다.
왼쪽으로 흐를 땐 트리를 그대로 사용해서 Index를 찾아가도 되는데,
오른쪽으로 흐를 땐 Subtree에서의 Index를 새롭게 구해야 한다(order - segment[node * 2] 부분)
*/
    // 아래 if문을 이해하는 것이 중요ㅠㅠ
    if (order <= segment[2 * node]) return next_kill(start, mid, 2 * node, order);
    else return next_kill(mid + 1, end, 2 * node + 1, order - segment[2 * node]);
}
