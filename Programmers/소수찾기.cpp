#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num){
    if (num<2) return false;
    
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    
    sort(numbers.begin(), numbers.end());
    
    set<int> primes;
    do{
        string tmp = "";
        for(char i : numbers){
            tmp += i;
            int num = stoi(tmp);
            if(isPrime(num)) primes.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return primes.size();
}
