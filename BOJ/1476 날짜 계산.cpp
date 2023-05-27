#include <iostream>

using namespace std;

int main(){
    long long EArr[10001];
    long long SArr[10001];
    long long MArr[10001];
    int E, S, M;
    cin >> E >> S >> M;

//E가 3이라면 E={3, 18, ...}
    for (int i=0; i<sizeof(EArr)/sizeof(EArr[0]); i++){
        EArr[i]=(15*i)+E;
        SArr[i]=(28*i)+S;
        MArr[i]=(19*i)+M;
    }

    for (int a=0; a<sizeof(SArr)/sizeof(SArr[0]); a++){   
        for (int b=0; b<sizeof(MArr)/sizeof(MArr[0]); b++){  
            if (MArr[b]>SArr[a]) break;

            for (int c=0; c<sizeof(EArr)/sizeof(EArr[0]); c++){
                if (EArr[c]>MArr[b]) break; 

                if ((EArr[c]==SArr[a])&&(EArr[c]==MArr[b])) {
                    cout << EArr[c] <<'\n';
                    return 0;//프로그램 종료
                }
            }
        }
    }
    return 0;
}
