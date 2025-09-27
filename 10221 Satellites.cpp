#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double s, a;
    string type;
    while(cin >> s >> a >> type){
        if(type == "min") a /= 60.0;
        while(a > 360.0) a -= 360.0;
        if(a > 180.0) a = 360.0-a; // 確保用小的角度才能算到小的arc值，否則會繞遠路
        double deg = a * M_PI / 180.0;
        double arc, chord;
        double r = 6440+s;
        arc = r * deg;
        chord = 2*r*sin(deg/2.0);
        cout << fixed << setprecision(6) << arc << ' ' << chord << '\n';
    }
    return 0;
}