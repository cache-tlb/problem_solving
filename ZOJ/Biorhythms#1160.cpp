#include <iostream>
#include <cstdio>

using namespace std;

int find_mf(int mi, int ni) {
    int mf = 1;
    while((mi*mf) % ni != 1){
        mf++;
    }
    return mf;
}

int main(int argc, char const *argv[])
{
    int a1, a2, a3, d;
    int T;
    scanf("%d", &T);
    int n1 = 23, n2 = 28, n3 = 33;
    int n = n1*n2*n3;
    int m1 = 28*33, m2 = 23*33, m3 = 23*28, m = 23*28*33;
    int c1 = m1*(find_mf(m1, n1) % n1), c2 = m2*(find_mf(m2, n2) % n2), c3 = m3*(find_mf(m3, n3) % n3);
    while(T--) {
        int tt = 0;
        while(scanf("%d%d%d%d", &a1, &a2, &a3, &d)){
            if(a1 < 0 && a2 < 0 && a3 < 0 && d < 0) break;
            int ans = ((a1*c1 + a2*c2 + a3*c3) % n + n - d) % n;
            printf("Case %d: the next triple peak occurs in %d days.\n", ++tt, ans ? ans : n);
        }
        if(T) printf("\n");
    }
    return 0;
}
