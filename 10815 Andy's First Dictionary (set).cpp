#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text;
    set<string> table;

    while(getline(cin, text)){
        for(char &c : text){
            if(isalpha(c)) c = tolower(c);
            else c = ' ';
            // 如果是字母，轉換成小寫
            // 否則轉成空格，方便sstream操作
        }
        stringstream ss(text);
        string token;
        while(ss >> token) table.insert(token);
        // 將ss資料根據空格 insert到set中
    }
    for(const auto &s : table){
        cout << s << '\n';
        // auto迭代器輸出
    }
    return 0;
}