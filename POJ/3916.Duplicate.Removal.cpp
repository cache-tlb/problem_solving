#include <cstdio>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        int x = -1, old = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x != old) {
                printf("%d ", x);
                old = x;
            }
        }
        printf("$\n");
    }
    return 0;
}
