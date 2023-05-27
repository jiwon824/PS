#include <iostream>

using namespace std;

int main(){
//1309 동물원
    int arr[100001][3]={0, };
    int mod= 9901;
    int n;
    cin >>n;

    arr[1][0]=1;
    arr[1][1]=1;
    arr[1][2]=1;
    for(int i=2;i<=n;i++){
        arr[i][0]= (arr[i-1][1]+arr[i-1][2])% mod;
        arr[i][1]= (arr[i-1][0]+arr[i-1][2])% mod;
        arr[i][2]= (arr[i-1][0]+arr[i-1][1]+arr[i-1][2])% mod;
    }
    cout << (arr[n][0]+arr[n][1]+arr[n][2])% mod <<'\n';
    return 0;
}
