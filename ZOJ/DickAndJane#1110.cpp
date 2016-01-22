#include <iostream>
#include <cstdio>

using namespace std;


int main(int argc, char const *argv[])
{
    int s,p,y,j;
    while(cin >> s >> p >> y >> j){
        // [Spot - Puff] = s
        // [Puff - Yertle] = p
        // [Spot - Yertle] = y
        // [Spot] + [Puff] + [Yertlr] = 12 + j
        // note that [a] <= a < [a] + 1, and thus [a] - [b] - 1 < a-b < [a] - [b] + 1
        // i.e. [a] - [b] - 1 <= [a-b] <= [a] - [b]
        // so [a-b] = [a] - [b] or [a-b] = [a] - [b] - 1
        for(int k = 0; k < 8; k++){
            int ds = k & 1;
            int dp = (k & 2) >> 1;
            int dy = (k & 4) >> 2;
            //printf("%d %d %d\n", ds, dp, dy);
            int m = s + ds, n = p + dp, l = y + dy;
            int a = (12+j+m+l)/3, b = a - m, c = (12+j+m-2*l)/3;
            if(a-b==m && b-c==n && a-c==l && a+b+c==12+j){
                printf("%d %d %d\n", a, b, c);
                break;
            }
        }
    }
    return 0;
}
