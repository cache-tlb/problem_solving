#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int x0,x1,x2;
    while(scanf("%d%d%d", &x0, &x1, &x2) != EOF){
        int c = x0, a = (x2 - x0) / 2 - (x1 - x0), b = x1 - c - a;
        printf("%d %d %d\n", a * 9 + b * 3 + c, a * 16 + b * 4 + c, a * 25 + b * 5 + c);
    }
    return 0;
}
