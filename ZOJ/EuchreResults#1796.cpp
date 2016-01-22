#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int bw, bl, cw, cl, zw, zl;
    while(scanf("%d%d%d%d%d%d", &bw, &bl, &cw, &cl, &zw, &zl) != EOF) {
        if(!bw && !bl && !cw && !cl && !zw && !zl) break;
        int d = (bw + cw + zw) - (bl + cl + zl);
        int s = (bw + bl);
        printf("Anna's won-loss record is %d-%d.\n", (s - d)/2,(s + d)/2);
    }
    return 0;
}
