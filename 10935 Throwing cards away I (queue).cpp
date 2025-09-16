#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    queue<int> card;
    vector<int> discarded;
    while(cin >> n){
        if(n == 0) break;
        discarded.clear();
        for(int i=1; i<=n; ++i){
            card.push(i);
        }
        while(card.front() != card.back()){
            discarded.push_back(card.front());
            card.pop();
            card.push(card.front());
            card.pop();
        }
        cout << "Discarded cards:";
        if(discarded.size() > 1){
            cout << ' ' << discarded[0];
            for(int i=1; i<discarded.size(); ++i){
                cout << ", " << discarded[i];
            }
        }
        else if(discarded.size() == 1) cout << ' ' << discarded[0];
        cout << '\n' << "Remaining card: " << card.front() << '\n';
        card.pop();
    }
    return 0;
}