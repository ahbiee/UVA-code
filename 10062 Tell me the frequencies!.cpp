#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first > b.first; // second = showed times, if equal, ASCII bigger will put at front
    return a.second < b.second; // otherwise the showed times lower will put at front
}

int main(){
    string text;
    bool first = true;
    while(getline(cin, text)){
        if(first) first = false;
        else cout << '\n';

        map<int, int> m;
        for(size_t i=0; i<text.length(); ++i){
            int num = int(text[i]);
            if(num >= 32 && num < 128)
                m[num]++; // get the showed times of each element
        }
        vector<pair<int, int>> freq(m.begin(), m.end()); // make pair of key to showed times
        sort(freq.begin(), freq.end(), cmp);
        for(auto &p : freq){
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}