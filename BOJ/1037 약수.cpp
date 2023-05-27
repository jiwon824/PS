#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> divisor;
    int n, number;
    cin >> n;

    for (int i = 0; i < n; i++) {
	cin >> number;
    divisor.push_back(number);
    }

    sort(divisor.begin(), divisor.end()); //algorithm 헤더 파일에 정의되어 있는 함수
    cout << (*divisor.begin()) * divisor.back();

    return 0;
}
