#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, u, d;
    while(scanf("%d%d%d", &n, &u, &d)){
        if(!n && !u && !d){
            break;
        }
        printf("%d\n", 2*(int)ceil((double)(n-d)/(double)(u-d))-1);
    }
    return 0;
}
