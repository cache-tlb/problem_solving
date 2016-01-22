//The leftmost bottom square of the chessboard is black
#include<iostream>
using namespace std;
const int MAX = 1000 + 10;
int s, x, y, dx, dy;
int ddx, ddy;
bool white()
{
    int i = y/s, j = x/s;
    if((i + j)%2 == 0) return false;
    else if(y%s==0 || x%s==0) return false;
    else return true;
}
int main()
{
    
    while(cin >> s >> x >> y >> dx >> dy){
        if(s==0) break;
        int step = 0;
        int ok = 0;
        ddx = dx%(2*s), ddy = dy%(2*s);
        if(white())
            cout << "After 0 jumps the flea lands at (" << x << ", " << y << ")." <<endl;
        else{
            for(int i = 0; i < MAX; i++){
                step++;
                x += dx;
                y += dy;
                if(white()){
                    ok = 1;
                    break;
                }    
            }
            if(ok){
                cout << "After " << step << " jumps the flea lands at (" 
                     << x << ", " << y << ")." << endl;
            }
            else cout << "The flea cannot escape from black squares." << endl;    
        }
    }    
    return 0;
}
