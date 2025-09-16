#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void multiply(vector<int> &v, int n){
    if(v.size() > 11) return;
    int carry = 0;
    for(int i=0; i<v.size(); ++i){
        int product = v[i] * n + carry;
        v[i] = product % 10;
        carry = product / 10;
    }
    while(carry > 0){
        v.push_back(carry % 10);
        carry /= 10;
    }
    return;
}

string factorial(int n){
    if(n == 0) return "1";

    vector<int> v = {1};

    for(int i=2; i<=n; ++i){
        multiply(v, i);
    }

    string result = "";

    for(int i=0; i<v.size(); ++i){
        result += to_string(v[i]);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(){
    string str;
    int n;
    while(cin >> n){
        str = factorial(n);
        if(str.size() >= 11) cout << "Overflow!\n";
        else if(str.size() < 5) cout << "Underflow!\n";
        else cout << str << '\n';
    }
    return 0;
}