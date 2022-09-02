#include <iostream>

using namespace std;

int main(){
    int a=0, b=0, c=0;
    int result;
    cin >> a >> b >> c;

    cout << (a+b)%c <<endl;
    cout << ((a%c) + (b%c))%c <<endl;
    cout << (a*b)%c <<endl;
    cout << ((a%c) * (b%c))%c <<endl;
    /*
    result =(a+b)%c;
    printf("%d\n", &result);
    
    result =((a%c) + (b%c))%c;
    printf("%d\n", &result);

    result = (a*b)%c;
    printf("%d\n", &result);

    result = ((a%c) * (b%c))%c;
    printf("%d\n", &result);
*/

    return 0;
}