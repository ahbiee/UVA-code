#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void multiply(vector<int> &v, int n){
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

    vector<int> result = {1};

    for(int i=2; i<=n; ++i){
        multiply(result, i);
    }

    string resultStr = "";
    for(size_t i=0; i<result.size(); ++i){
        resultStr += to_string(result[i]);
    }

    reverse(resultStr.begin(), resultStr.end());
    
    return resultStr;
}

int main(){
    string str;
    int n;
    while(cin >> n){
        str.clear();
        str = factorial(n);

        cout << n << "!\n" << str << '\n';
    }
    return 0;
}