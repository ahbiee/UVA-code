#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void multiply(vector<int> &v, int n){
    int carry = 0;

    for(int i=0; i<v.size(); ++i){
        int product = v[i] * n + carry;
        v[i] = product % 10;
        carry = product / 10;
    }

    while(carry > 0){
        v.push_back(carry%10);
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

    for(size_t i=0; i<v.size(); ++i){
        result += to_string(v[i]);
    }

    return result;
}

int main(){
    string str;
    int n;
    while(cin >> n){
        str.clear();
        str = factorial(n);
        while(str[0] == '0'){
            str.erase(str.begin(),  str.begin()+1);
        }
        cout.width(5);
        cout << n;
        cout << " -> " << str[0] << '\n';
    }
    return 0;
}