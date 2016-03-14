#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    printf("Gnomes:\n");
    while (T--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b && b > c) printf("Ordered\n");
        else if (a < b && b < c) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}
