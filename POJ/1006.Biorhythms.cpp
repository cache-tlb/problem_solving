#include <cstdio>

int get_t(int m, int M) {
    int t = 1;
    while (t*M % m != 1) t++;
    return t;
}

int main() {
    const int m1 = 23, m2 = 28, m3 = 33;
    int M = m1*m2*m3;
    int M1 = M/m1, M2 = M/m2, M3 = M/m3;
    int t1 = get_t(m1, M1), t2 = get_t(m2, M2), t3 = get_t(m3, M3);
    int p, e, i, d;
    int t = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d) != EOF) {
        if (p == -1 && e == -1 && i == -1 && d == -1)  break;
        int ans = p*t1*M1 + e*t2*M2 + i*t3*M3 - d;
        ans = ans % M;
        while (ans <= 0) ans += M;
        printf("Case %d: the next triple peak occurs in %d days.\n", t++, ans);
    }
    return 0;
}
