#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int my_round(double x) {
    return int(x+0.5);
}

int main(int argc, char const *argv[])
{
    int x, y;
    string line;
    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> x >> y;
        double dist = 0.0;
        while(getline(cin, line)){
            if(line=="java") break;
            istringstream is(line);
            double x1, y1, x2, y2;
            is >> x1 >> y1 >> x2 >> y2;
            dist += hypot(x2-x1, y2-y1);
        }
        int minite = my_round(dist / 10000.0 * 60);
        printf("%d:%02d\n", minite/60, minite%60);
    }
    return 0;
}
