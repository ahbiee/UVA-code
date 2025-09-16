#include <iostream>
#include <sstream>

using namespace std;

bool scent[51][51] = {false};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int border_x, border_y;
    cin >> border_x >> border_y;   

    int x, y;
    char face, act;
    int facedeg;
    bool lost;
    string str;

    while(cin >> x >> y >> face >> ws){
        cin >> str;
        lost = false;
        facedeg = 0;
        switch(face){
            case 'N': facedeg += 0; break;
            case 'E': facedeg += 90; break;
            case 'S': facedeg += 180; break;
            case 'W': facedeg += 270; break;
        }
        
        stringstream ss(str);

        while(ss >> act){
            if(lost) break;

            switch(act){
                case 'L':{
                    facedeg = (facedeg-90+360)%360;
                    break;
                }
                case 'R':{
                    facedeg = (facedeg+90) %360;
                    break;
                }
                case 'F':{
                    int prev_x = x, prev_y = y;
                    if(facedeg == 0) ++y;
                    else if(facedeg == 90) ++x;
                    else if(facedeg == 180) --y;
                    else if(facedeg == 270) --x;

                    if(x > border_x || x < 0 || y > border_y || y < 0){
                        if(scent[prev_x][prev_y]){
                            x = prev_x;
                            y = prev_y;
                        }
                        else{
                            scent[prev_x][prev_y] = true;
                            lost = true;
                            x = prev_x;
                            y = prev_y;
                        }
                    }
                    break;
                }
            }
        }

        if(facedeg == 0) face = 'N';
        else if(facedeg == 90) face = 'E';
        else if(facedeg == 180) face = 'S';
        else if(facedeg == 270) face = 'W';

        cout << x << ' ' << y << ' ' << face << (lost ? " LOST\n" : "\n");
    }
    return 0;
}