#include <iostream>
#include <vector>

#define MAX 500000
using namespace std;

vector<int> v;
int N;
long long ans=0;

void merge(int start, int mid, int end, int left, int right);
void mergeSort(int start,int end);
int main(){
    // 첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다.
    cin >> N;
    // 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다.
    // 각각의 A[i]는 0 ≤ |A[i]| ≤ 1,000,000,000의 범위에 들어있다.
    // int 최대값-2,147,483,648 ~ 2,147,483,647 범위 내
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    mergeSort(0, N-1);
    cout << ans << '\n';
    return 0;
}
void mergeSort(int start,int end){
    int mid = (start+end)/2;
    int left=start;
    int right=mid+1;

    if (start==end) return;

    mergeSort(start, mid);
    mergeSort(mid+1, end);

    merge(start, mid, end, left, right);
}

void merge(int start, int mid, int end, int left, int right){
    vector<int> tmp;
    // tmp에 크기 순서로 정렬하기
    while (left<=mid && right<=end){
        if (v[left]<=v[right]){
            tmp.push_back(v[left++]);
            // 아래 코드와 동일한 코드
            // tmp.push_back(v[left]);
            // left++;
        }
        // 앞뒤 순서가 바뀌어야 하는 상태, 두 수가 떨어진 거리만큼 ans에 더하기
        else{
            tmp.push_back(v[right++]);
            ans+=(mid+1-left);
        }
    }
    while (left<=mid){
        tmp.push_back(v[left++]);
    }
    while (right<=end){
        tmp.push_back(v[right++]);
    }

    // tmp에 정렬한 순서로 원본 벡터 v 변경해주기
    for (int i=start,j=0; i<=end; i++,j++){
        v[i]=tmp[j];
    }
}
