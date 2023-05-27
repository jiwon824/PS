#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, test_num;
    long long sum;

    cin >> test_num;

	for (int t=0; t<test_num; t++){
        sum = 0;
        cin >> n;
        for (int i=1; i<=n; i++){ 
	    sum += i*(n/i);
	    }
        cout << sum << '\n';
    }    
	
    return 0;
}
