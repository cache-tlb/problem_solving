#include <cstdio>
  
long long exgcd(long long a,long long b,long long &x,long long &y) {
    long long r, t;
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    r = exgcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a/b*y;
  
    return r;  
}

int main() {
    long long x, y, m, n, L;
    long long d, r, xx, yy;
  
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L) != EOF) {
        d = exgcd( n - m, L, xx, yy);//求得最大公约数
  
        if( (x-y) % d ) {  
            printf("Impossible\n");
            continue;
        }
  
        xx = xx*((x-y)/d);
        r = L/d;
        xx = (xx%r+r)%r;

        printf("%lld\n",xx);
    }
    return 0;
}

/*
Sample Input
1 2 3 4 5
Sample Output
4


Impossible


x≠y < 2000000000，0 < m、n < 2000000000，0 < L < 2100000000。
*/