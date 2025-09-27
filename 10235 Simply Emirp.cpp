#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    if(num == 1) return false;
    if(num == 2 || num == 3) return true;
    if(num%2 == 0 || num % 3 == 0) return false;
    for(int i=5; i*i<=num; i+=6){
        if(num%i == 0 || num%(i+2) == 0) return false;
    }
    return true;
}

bool isEmirp(int num){
    string str = to_string(num);
    reverse(str.begin(), str.end());
    int n = stoi(str);
    if(n == num) return false;
    return isPrime(n);
}

int main(){
    int n;
    while(cin >> n){
        bool prime = isPrime(n);
        bool emirp = isEmirp(n);
        if(emirp && prime) cout << n << " is emirp.\n"; // 要同時有prime和emirp才是 emirp，否則就算反轉後是prime，該數仍然為not prime
        else if(prime) cout << n << " is prime.\n";
        else cout << n << " is not prime.\n";
    }
    return 0;
}