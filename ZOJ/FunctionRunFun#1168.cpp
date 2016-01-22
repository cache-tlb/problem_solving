#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 32;

int cache[MAXN][MAXN][MAXN];

int f(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) {
        return f(20,20,20);
    }
    if(cache[a][b][c] >= 0) return cache[a][b][c];
    if(a < b && b < c){
        int ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
        cache[a][b][c] = ret;
        return ret;
    }
    else {
        int ret = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
        cache[a][b][c] = ret;
        return ret;
    }
}

int main(int argc, char const *argv[])
{
    int x, y, z;
    memset(cache, -1, sizeof(cache));
    while(scanf("%d%d%d", &x, &y, &z) != EOF) {
        if(x==-1 && y==-1 && z==-1) break;
        printf("w(%d, %d, %d) = %d\n", x, y, z, f(x, y, z));
    }
    return 0;
}
