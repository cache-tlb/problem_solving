#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

const double pi = 3.14159;

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    while(cin >> line){
        if(line == "ENDOFINPUT") break;
        double r, theta, g;
        cin >> r >> g >> theta;
        if(theta > 180)
            theta = 360 - theta;
        double len = r*theta/180.0*2*pi;
        double gg = len/5;
        if(gg <= g){
            cout << "YES " << (int)(g-gg) << endl;
        }
        else{
            cout << "NO " << (int)(g*5.0) << endl;
        }
        cin >> line;
    }
    return 0;
}
