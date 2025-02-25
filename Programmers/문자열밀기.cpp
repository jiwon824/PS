#include <string>
#include <vector>

using namespace std;

string shift(string A){
    int len = A.length();
    char c = A[len-1];
    for(int i=len-1; i>0; i--){
        A[i]=A[i-1];
    }
    A[0]=c;
    return A;
}

int solution(string A, string B) {
    if(A==B) return 0;
    
    int answer = 0;
    
    string init = A;
    while(true){
        A = shift(A);
        answer++;
        if(A==init) return -1;
        if(A==B) return answer;
    }
    return 0;
}
