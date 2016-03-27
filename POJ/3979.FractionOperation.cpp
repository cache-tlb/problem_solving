#include <cstdio>

int gcd(int a, int b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    int x1, y1, x2, y2;
    char op;
    while (scanf("%d/%d%c%d/%d", &x1, &y1, &op, &x2, &y2) != EOF) {
        int denom = y1*y2;
        int numer1 = x1*y2, numer2 = x2*y1;
        int numer = (op == '+' ? numer1 + numer2 : numer1 - numer2);
        if (numer == 0) printf("0\n");
        else {
            int g = gcd(numer, denom);
            if (g < 0) g = -g;
            denom /= g;
            numer /= g;
            if (denom == 1) printf("%d\n", numer);
            else printf("%d/%d\n", numer, denom);
        }
    }
    return 0;
}
