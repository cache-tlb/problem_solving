#include <cstdio>

int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int STEP, MOD;
    while (scanf("%d%d", &STEP, &MOD) != EOF) {
        printf("% 10d% 10d    ", STEP, MOD);
        bool ok = (gcd(STEP, MOD) == 1);
        if (ok) printf("Good Choice");
        else printf("Bad Choice");
        printf("\n\n");
    }
    return 0;
}
