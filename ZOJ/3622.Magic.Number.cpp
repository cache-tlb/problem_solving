#include <cstdio>

bool check(int x) {
    while (x % 10 == 0) {
        x /= 10;
    }
    while (x % 5 == 0) {
        x /= 5;
    }
    return (x==1 || x==2);
}

int main() {
    int n, m;
    long long trial[] = {1, 2, 5, 25, 125};
    while (scanf("%d%d", &m, &n) != EOF) {
        int cnt = 0;
        long long lm = m, ln = n;
        for (int i = 0; i < 5; i++) {
            long long base = trial[i];
            while (base <= ln) {
                if (base >= lm && base <= ln) cnt ++;
                base *= 10;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
